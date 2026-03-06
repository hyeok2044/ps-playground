#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  int m, n, k;
  cin >> m >> n >> k;

  int arr1[m];
  int arr2[n];

  for (int i = 0; i < m; i++) {
    cin >> arr1[i];
  }

  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }
  bool ans = false;
  for (int i = 0; i + m - 1 < n; i++) {
    bool chk = true;
    for (int j = 0; j < m; j++) {
      if (arr2[i + j] != arr1[j]) {
        chk = false;
      }
    }
    ans |= chk;
  }
  if (ans)
    cout << "secret" << endl;
  else
    cout << "normal" << endl;
}
