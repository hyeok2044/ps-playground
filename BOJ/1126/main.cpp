#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

/* check the illustration on the readme file */

int dp[51][500001];
int main(void)
{
  memset(dp, -1, 51 * 500001 * sizeof(int));
  dp[0][0] = 0;
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int h;
    cin >> h;
    for (int j = 0; j <= 500000; j++) {
      if (dp[i][j] < 0)
        continue;
      if (h >= j) {
        // case 1 - 1
        dp[i + 1][h - j] = max(dp[i + 1][h - j], dp[i][j] + j);
        dp[i + 1][j]     = max(dp[i + 1][j], dp[i][j]); // case 1 - 2
        // case 1 - 3
        if (h + j <= 500000)
          dp[i + 1][h + j] = max(dp[i + 1][h + j], dp[i][j]);
      } else {
        // case 2 - 1
        dp[i + 1][j - h] = max(dp[i + 1][j - h], dp[i][j] + h);
        dp[i + 1][j]     = max(dp[i + 1][j], dp[i][j]); // case 2 - 2
        // case 2 - 3
        if (h + j <= 500000)
          dp[i + 1][h + j] = max(dp[i + 1][h + j], dp[i][j]);
      }
    }
  }
  if (dp[n][0]) {
    cout << dp[n][0] << endl;
  } else {
    cout << -1 << endl;
  }
}
