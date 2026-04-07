#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int  H, W;
int  arr[129][129];
bool chk[129][129];

void dfs(int r, int c, int from)
{
  chk[r][c] = true;
  for (int d = 0; d < 4; d++) {
    int nr = r + dr[d];
    int nc = c + dc[d];
    if (arr[nr][nc] == from && !chk[nr][nc]) {
      dfs(nr, nc, from);
    }
  }
}

void query(int r, int c, int from, int to)
{
  for (int i = 0; i <= H; i++) {
    for (int j = 0; j <= W; j++) {
      chk[i][j] = false;
    }
  }

  dfs(r, c, from);

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (chk[i][j])
        arr[i][j] = to;
    }
  }
}
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> H >> W;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> arr[i][j];
    }
  }

  int Q;
  cin >> Q;
  while (Q--) {
    int a, b, c;
    cin >> a >> b >> c;
    query(a, b, arr[a][b], c);
  }

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
