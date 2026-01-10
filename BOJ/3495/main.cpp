#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 3495 2026-01-10 07:24 ~ 07:29
// inside: odd number of line encounter.

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int area = 0;
  for (int i = 0; i < n; i++) {
    int encounter = 0;
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      if (c == '/' || c == '\\') {
        encounter++;
        area++;
      } else {
        if (encounter % 2 == 1) {
          area += 2;
        }
      }
    }
  }
  cout << area / 2 << endl;
}
