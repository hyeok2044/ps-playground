#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

/*
 * fibonacci
 */

ll  fib[100];
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  fib[0] = 0;
  fib[1] = 1;

  ll n;
  cin >> n;
  for (ll i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  cout << fib[n - 1] << " " << fib[n] << endl;
}
