#include <bits/stdc++.h>
#include <cstddef>

using namespace std;

typedef long long int ll;

#define endl '\n';

ll toBaseTen(int n)
{
  ll     res = 0;
  string s;
  while (n > 0) {
    if (n % 2 == 0) {
      s += '0';
    } else {
      s += '1';
    }
    n /= 2;
  }
  reverse(s.begin(), s.end());
  res = stol(s);
  return res;
}
/*
 * base 10 divisible by n: bruteforce.
 */
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    int i   = 1;
    ll  ans = 0;
    while (true) {
      ans = toBaseTen(i++);
      if (ans % n == 0)
        break;
    }
    cout << ans << endl;
  }
}
