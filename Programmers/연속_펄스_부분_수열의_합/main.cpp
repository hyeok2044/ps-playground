#include <algorithm>
#include <vector>

using namespace std;

// 2026-01-09 09:40

typedef long long ll;

long long solution(vector<int> sequence)
{
  int n = sequence.size();
  for (int i = 0; i < n; i++) {
    if (i % 2)
      sequence[i] *= -1;
  }
  ll memo[n + 1];
  ll negMemo[n + 1];
  memo[0]    = 0;
  negMemo[0] = 0;

  // memo[i] : max sum including this.
  for (int i = 1; i <= n; i++) {
    memo[i]    = sequence[i - 1] + max(memo[i - 1], 0ll);
    negMemo[i] = sequence[i - 1] + min(negMemo[i - 1], 0ll);
  }

  long long answer = 0;
  for (int i = 0; i <= n; i++) {
    answer = max(memo[i], answer);
    answer = max(-negMemo[i], answer);
  }
  return answer;
}
