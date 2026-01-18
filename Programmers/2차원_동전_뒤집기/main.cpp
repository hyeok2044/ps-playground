#include <vector>

using namespace std;

// 2026-01-19 04:35 ~ 04:47

int solution(vector<vector<int>> beginning, vector<vector<int>> target)
{

  int n = beginning.size();
  int m = beginning[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      beginning[i][j] = beginning[i][j] ^ target[i][j];
    }
  }
  int answer = 0;

  for (int i = 0; i < n; i++) {
    if (beginning[i][0] == 1) {
      for (int j = 0; j < m; j++) {
        beginning[i][j] = !beginning[i][j];
      }
      answer++;
    }
  }
  for (int i = 0; i < m; i++) {
    if (beginning[0][i] == 1) {
      for (int j = 0; j < n; j++) {
        beginning[j][i] = !beginning[j][i];
      }
      answer++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (beginning[i][j])
        return -1;
    }
  }

  return min(m + n - answer, answer);
}
