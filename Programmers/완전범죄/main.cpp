#include <string>
#include <vector>

using namespace std;
bool memo[121][121];

int solution(vector<vector<int>> info, int n, int m)
{

  int answer;
  memo[0][0] = true;
  for (vector<int> item : info) {
    for (int i = 120; i >= 0; i--) {
      for (int j = 120; j >= 0; j--) {
        if (memo[i][j]) {
          memo[i + item[0]][j] = true;
          memo[i][j + item[1]] = true;
        }
        memo[i][j] = false;
      }
    }
  }
  int ans = 987654321;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (memo[i][j]) {
        ans = min(ans, i);
      }
    }
  }
  if (ans == 987654321)
    answer = -1;
  else
    answer = ans;
  return answer;
}
