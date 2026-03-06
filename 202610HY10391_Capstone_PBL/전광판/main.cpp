#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-03-03 20:53 ~ 21:12
/*
 *  _  0
 * |_| 1 2 3
 * |_| 4 5 6
 */

// 0 1 2 3 4 5 6 7 8 9 X
bool numbers[11][7] = {
    {1, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 0},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 0, 1},
    {1, 1, 1, 0, 0, 1, 1},
    {1, 1, 1, 0, 1, 1, 1},
    {1, 1, 0, 1, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0}
};

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int TC;
  cin >> TC;
  for (int t = 0; t < TC; t++) {
    int arr_a[5];
    int arr_b[5];
    int a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
      arr_a[i] = a % 10;
      if (a == 0)
        arr_a[i] = 10;
      a /= 10;
      arr_b[i] = b % 10;
      if (b == 0)
        arr_b[i] = 10;
      b /= 10;
      for (int j = 0; j < 7; j++) {
        ans += numbers[arr_a[i]][j] ^ numbers[arr_b[i]][j];
      }
    }
    cout << ans << endl;
  }
}
