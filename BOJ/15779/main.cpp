#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  // initial
  int a1, a2;
  cin >> a1 >> a2;
  int cnt    = 2;
  int streak = 2;
  for (int i = 2; i < n; i++) {
    bool chk = true;
    int  a3;
    cin >> a3;
    // condition
    if (a1 <= a2 && a2 <= a3)
      chk = false;
    if (a1 >= a2 && a2 >= a3)
      chk = false;
    if (chk) {
      streak++;
      cnt = max(cnt, streak);
    } else {
      streak = 2; // 1 2 3 -> 2 3 is still a candidate.
    }
    // propagate
    a1 = a2;
    a2 = a3;
  }
  cout << cnt << endl;
}
