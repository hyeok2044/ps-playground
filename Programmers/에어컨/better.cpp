#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef pair<int, int> pii;
typedef vector<pii>    vpii;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard)
{
  {
    int d = 80;
    temperature += d;
    t1 += d;
    t2 += d;
  }
  int n = onboard.size();

  vector<vi> dp(n + 1, vi(201, 1e9));
  dp[0][temperature] = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 200; j++) {
      if (onboard[i - 1] && !(t1 <= j && j <= t2))
        continue;
      for (int k = max(0, j - 1); k <= min(200, j + 1); k++) {
        if (abs(j - temperature) > abs(k - temperature))
          dp[i][k] = min(dp[i][k], dp[i - 1][j]); // 실외 온도 방향
        if (j == k)
          dp[i][k] = min(
              dp[i][k],
              dp[i - 1][j] +
                  (j == temperature ? 0 : b)); // 현재 온도를 실내 온도로 설정
        dp[i][k] = min(dp[i][k], dp[i - 1][j] + a); // 실내 온도 변경
      }
    }
  }

  return *min_element(all(dp[n]));
}
