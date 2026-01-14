#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-01-14 08:30 ~ 08:50
// 9301 Painting Party

char arr[100][100];

// converter
void color(int x, int y, char c)
{
  int row          = 100 - y;
  int column       = x - 1;
  arr[row][column] = c;
}
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
        arr[i][j] = '.';
      }
    }

    cin.ignore();

    for (int cmd = 0; cmd < m; cmd++) {
      string str;
      getline(cin, str);
      stringstream ss(str);
      string       type;
      int          x, y, w, h;
      char         c;
      ss >> type >> x >> y >> w >> h >> c;
      if (type == "Filled") {
        for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
            color(x + j, y + i, c);
          }
        }
      } else if (type == "Empty") {
        for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
            if ((i != 0 && i != h - 1) && (j != 0 && j != w - 1))
              continue;
            color(x + j, y + i, c);
          }
        }
      }
    }
    cout << "Case " << tc << ":" << endl;
    for (int i = 99 - n + 1; i <= 99; i++) {
      for (int j = 0; j < n; j++) {
        cout << arr[i][j];
      }
      cout << endl;
    }
  }
}
