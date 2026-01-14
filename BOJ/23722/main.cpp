#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-01-14 08:57 ~ 09:05
// 23722 Marbles Tell Your Lucky Number

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (!(a == 0 && b == 0 && c == 0 && d == 0)) {
    vector<pair<int, int>> vec;
    vec.emplace_back(a, 0);
    vec.emplace_back(b, 1);
    vec.emplace_back(c, 2);
    vec.emplace_back(d, 3);
    sort(vec.begin(), vec.end());

    while (vec.size() > 1) {
      for (int i = 1; i < vec.size(); i++) {
        vec[i].first -= vec[0].first;
      }

      vector<pair<int, int>> vec2;
      for (int i = 0; i < vec.size(); i++) {
        if (vec[i].first != 0) {
          vec2.push_back(vec[i]);
        }
      }
      vec = vec2;
      sort(vec.begin(), vec.end());
    }
    cout << vec[0].first << endl;
    cin >> a >> b >> c >> d;
  }
}
