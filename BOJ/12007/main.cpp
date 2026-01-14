#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 12007
// 2026-01-14 06:16
//

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;

  vector<pair<int, int>> cow;
  vector<int>            x;
  vector<int>            y;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cow.emplace_back(a, b);
    x.emplace_back(a);
    y.emplace_back(b);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());

  int answer = 0x7fffffff;
  for (int i = 0; i < n; i++) {
    int minx = x[0], miny = y[0];
    int maxx = x[x.size() - 1], maxy = y[y.size() - 1];
    if (cow[i].first == minx)
      minx = x[1];
    if (cow[i].first == maxx)
      maxx = x[x.size() - 2];
    if (cow[i].second == miny)
      miny = y[1];
    if (cow[i].second == maxy)
      maxy = y[y.size() - 2];
    answer = min(answer, (maxx - minx) * (maxy - miny));
  }
  cout << answer << endl;
}
