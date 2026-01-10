#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 26853
// 2026-01-10  07:50 ~ 08:04

int occurrence[100][26];

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      occurrence[j][s[j] - 'a']++;
    }
  }

  int ans = n * m;

  for (int i = 0; i < m; i++) {
    int mxm = 0;
    for (int j = 0; j < 26; j++) {
      mxm = max(mxm, occurrence[i][j]);
    }
    ans -= mxm;
  }
  cout << ans << endl;
}
