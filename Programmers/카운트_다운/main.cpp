#include <vector>

using namespace std;

// 2026-01-21 05:18 ~ 05:27

int convert(int a, int b)
{
  return a * 1000000 + b;
}

pair<int, int> revert(int n)
{
  pair<int, int> p = {n / 1000000, n % 1000000};
  return p;
}

int dp[100001];

vector<int> solution(int target)
{
  vector<int> answer;
  for (int i = 0; i <= 100000; i++) {
    dp[i] = 0x7fff'ffff;
  }
  dp[0] = 0;
  for (int i = 0; i <= 100000; i++) {
    pair<int, int> p = revert(dp[i]);
    int            a = p.first;
    int            b = p.second;
    for (int j = 1; j <= 20; j++) {
      if (i + j <= 100000) {
        dp[i + j] = min(dp[i + j], convert(a + 1, b));
      }
    }

    if (i + 50 <= 100000) {
      dp[i + 50] = min(dp[i + 50], convert(a + 1, b));
    }

    for (int j = 2; j <= 40; j += 2) {
      if (i + j <= 100000) {
        dp[i + j] = min(dp[i + j], convert(a + 1, b + 1));
      }
    }

    for (int j = 3; j <= 60; j += 3) {
      if (i + j <= 100000) {
        dp[i + j] = min(dp[i + j], convert(a + 1, b + 1));
      }
    }
  }
  pair<int, int> ans = revert(dp[target]);
  answer.push_back(ans.first);
  answer.push_back(ans.first - ans.second);
  return answer;
}
