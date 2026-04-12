#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// E S W N, CW: ++, CCW: --
int  dr[4]       = {0, 1, 0, -1};
int  dc[4]       = {1, 0, -1, 0};
char startDir[4] = {'>', 'v', '<', '^'};

typedef struct startpos {
  int r;
  int c;
  int dir;
} startpos;
char mp[27][27];

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int h, w;
  cin >> h >> w;
  for (int i = 0; i < 27; i++) {
    for (int j = 0; j < 27; j++) {
      mp[i][j] = '.';
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> mp[i][j];
    }
  }

  startpos sp = {0, 0, 0};
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      int cnt = 0;
      int d   = 0;
      if (mp[i][j] != '#') {
        continue;
      }
      for (int dir = 0; dir < 4; dir++) {
        if (mp[i + dr[dir]][j + dc[dir]] == '#') {
          cnt++;
          d = dir;
        }
      }

      if (cnt == 1)
        sp = {i, j, d};
    }
  }

  vector<char> cmd;

  int cnt = 1;
  int cd  = sp.dir;
  int d   = 0;
  int r   = sp.r;
  int c   = sp.c;
  while (cnt > 0) {
    mp[r][c] = '.';
    cnt      = 0;
    for (int dir = 0; dir < 4; dir++) {
      if (mp[r + dr[dir]][c + dc[dir]] == '#') {
        cnt++;
        d = dir;
      }
    }
    if (cnt == 0) {
      break;
    }
    int d_diff = d - cd + 4;
    d_diff %= 4;
    if (d_diff == 1) {
      cmd.push_back('R');
    } else if (d_diff == 3) {
      cmd.push_back('L');
    }

    for (int i = 0; i < 2; i++) {
      r += dr[d];
      c += dc[d];
      mp[r][c] = '.';
    }
    cmd.push_back('A');
    cd = d;
  }

  cout << sp.r << " " << sp.c << endl;
  cout << startDir[sp.dir] << endl;
  for (char ch : cmd) {
    cout << ch;
  }
  cout << endl;
}
