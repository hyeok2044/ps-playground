#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-01-14 07:28 ~ 07:32
// 14378 Rank and File (Large)

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    int n;
    cin >> n;
    set<int> s;
    for (int i = 0; i < 2 * n - 1; i++) {
      for (int j = 0; j < n; j++) {
        int tmp;
        cin >> tmp;
        if (s.find(tmp) != s.end()) {
          s.erase(tmp);
        } else {
          s.insert(tmp);
        }
      }
    }

    cout << "Case #" << tc << ": ";
    for (int tmp : s) {
      cout << tmp << " ";
    }
    cout << endl;
  }
}
