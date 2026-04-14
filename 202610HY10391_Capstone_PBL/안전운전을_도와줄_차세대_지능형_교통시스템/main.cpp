#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// d r u l
int  dr[4] = {1, 0, -1, 0};
int  dc[4] = {0, 1, 0, -1};
bool visited[102][102];
bool cur[102][102][4];
bool nxt[102][102][4];

// modulo 0: v modulo 1: >
// modulo 2: ^ modulo 3: <
vector<int> signs[13] = {
    {},
    {0, 1, 2},
    {1, 2, 3},
    {0, 2, 3},
    {0, 1, 3},
    {1, 2},
    {2, 3},
    {0, 3},
    {0, 1},
    {0, 1},
    {1, 2},
    {2, 3},
    {0, 3}
};

int corners[102][102][4];
int N, T;

// 40000개를 100번 해도 상관 없으니까 현재 위치 + 방향을 저장해서 킵고잉 하면
// 됨.

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N >> T;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      for (int k = 0; k < 4; k++) {
        cin >> corners[i][j][k];
      }
    }
  }
  nxt[1][1][2]  = true;
  visited[1][1] = true;

  int t = 0;

  while (t < T) {

    // initialize
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        for (int k = 0; k < 4; k++) {
          cur[i][j][k] = nxt[i][j][k];
          nxt[i][j][k] = 0;
        }
      }
    }

    for (int r = 1; r <= N; r++) {
      for (int c = 1; c <= N; c++) {
        for (int k = 0; k < 4; k++) {
          // in place and right sign direction?
          int signNo = corners[r][c][t % 4];
          if (cur[r][c][k] && (signNo % 4 == k)) {
            for (int nxtDir : signs[signNo]) {
              int nr = r + dr[nxtDir];
              int nc = c + dc[nxtDir];
              if (nr < 1 || nr > N || nc < 1 || nc > N)
                continue;
              nxt[nr][nc][nxtDir] = true;
              visited[nr][nc]     = true;
            }
          }
        }
      }
    }

    t++;
  }

  int cnt = 0;
  for (int r = 1; r <= N; r++) {
    for (int c = 1; c <= N; c++) {
      if (visited[r][c])
        cnt++;
    }
  }
  cout << cnt << endl;
}
