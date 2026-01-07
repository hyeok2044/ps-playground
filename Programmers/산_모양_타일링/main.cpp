#include <vector>

using namespace std;

typedef long long int ll;

ll  memo[300000];
int solution(int n, vector<int> tops)
{
  memo[0] = 1;
  memo[1] = 1;
  for (int i = 0; i < n; i++) {
    if (tops[i]) {
      memo[i * 2 + 2] = (memo[i * 2] + 2 * memo[i * 2 + 1]) % 10007;
      memo[i * 2 + 3] = (memo[i * 2 + 1] + memo[i * 2 + 2]) % 10007;
    } else {
      memo[i * 2 + 2] = (memo[i * 2] + memo[i * 2 + 1]) % 10007;
      memo[i * 2 + 3] = (memo[i * 2 + 1] + memo[i * 2 + 2]) % 10007;
    }
  }
  int answer = memo[n * 2 + 1];
  return answer;
}
