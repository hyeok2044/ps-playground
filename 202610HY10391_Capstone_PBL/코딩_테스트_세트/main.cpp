#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long int ll;

#define endl '\n'

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n, T;
  cin >> n >> T;
  while (T--) {
    // X 0 X 1 X 2 X
    ll arr[2 * n + 1];
    ll arr_cpy[2 * n + 1];
    ll required[n];
    for (int i = 1; i <= 2 * n - 1; i++) {
      cin >> arr[i];
    }
    arr[0]     = 0;
    arr[2 * n] = 0;

    ll l   = 0;
    ll r   = 1e13;
    ll ans = 0;
    while (l <= r) {
      ll mid = (l + r) / 2;

      for (int i = 0; i <= 2 * n; i++) {
        arr_cpy[i] = arr[i];
      }

      for (int i = 0; i < n; i++) {
        required[i] = mid;
        if (required[i] > arr_cpy[i * 2 + 1]) {
          required[i] -= arr_cpy[i * 2 + 1];
          arr_cpy[i * 2 + 1] = 0;
        } else {
          arr_cpy[i * 2 + 1] -= required[i];
          required[i] = 0;
        }
      }

      bool chk = true;
      for (int i = 0; i < n; i++) {
        if (required[i] > arr_cpy[i * 2]) {
          required[i] -= arr_cpy[i * 2];
          arr_cpy[i * 2] = 0;
        } else {
          arr_cpy[i * 2] -= required[i];
          required[i] = 0;
        }

        if (required[i] > arr_cpy[i * 2 + 2]) {
          chk = false;
          break;
        } else {
          arr_cpy[i * 2 + 2] -= required[i];
          required[i] = 0;
        }
      }

      if (chk) {
        l   = mid + 1;
        ans = mid;
      } else {
        r = mid - 1;
      }
    }
    cout << ans << endl;
  }
}
