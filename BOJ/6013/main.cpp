#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-01-14 09:10 ~ 09:16
// 6013 Lonesome Partners

vector<pair<int, int>> vec;
int                    main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> ans(2);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    vec.emplace_back(x, y);
  }
  int distMax = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int dx   = vec[i].first - vec[j].first;
      int dy   = vec[i].second - vec[j].second;
      int dist = dx * dx + dy * dy;
      if (dist > distMax) {
        ans[0]  = i + 1;
        ans[1]  = j + 1;
        distMax = dist;
      }
    }
  }
  cout << ans[0] << " " << ans[1] << endl;
}
