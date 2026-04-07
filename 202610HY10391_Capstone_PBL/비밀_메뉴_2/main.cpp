#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

int n, m, k;
int a[3001], b[3001];
int arr[3001][3001];

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }

  int mxm = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int &cur = arr[i][j];
      if (a[i] == b[j]) {
        cur = arr[i - 1][j - 1] + 1;
        mxm = max(cur, mxm);
      } else {
        cur = 0;
      }
    }
  }
  cout << mxm << endl;
}
