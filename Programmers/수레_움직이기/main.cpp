#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 2026-01-09 07:50 (1h 30m failed)

class pos
{
public:
  int r;
  int c;

  pos(int r, int c) : r(r), c(c){};

  void print()
  {
    cout << r << ", " << c << " ";
  }
};

class state
{
public:
  pos                  redPos;
  pos                  bluePos;
  vector<vector<bool>> redChk;
  vector<vector<bool>> blueChk;
  int                  moves;

  state(pos                  rp,
        pos                  bp,
        vector<vector<bool>> redChk,
        vector<vector<bool>> blueChk,
        int                  moves)
      : redPos(rp), bluePos(bp), moves(moves)
  {
    this->redChk  = redChk;
    this->blueChk = blueChk;
  };

  void print()
  {
    if (moves > 5)
      return;
    redPos.print();
    bluePos.print();
    for (auto a : redChk) {
      for (auto b : a) {
        cout << b;
      }
      cout << " ";
    }
    cout << " // ";
    for (auto a : blueChk) {
      for (auto b : a) {
        cout << b;
      }
      cout << " ";
    }
    cout << endl;
    cout << moves << endl;
  }
};

int solution(vector<vector<int>> maze)
{
  int R = maze.size(), C = maze[0].size();
  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  vector<vector<bool>> redChk, blueChk;
  for (int i = 0; i < R; i++) {
    vector<bool> vec;
    for (int j = 0; j < C; j++) {
      vec.push_back(false);
    }
    redChk.push_back(vec);
    blueChk.push_back(vec);
  }

  pos redPos  = {0, 0};
  pos bluePos = {0, 0};

  pos redDest  = {0, 0};
  pos blueDest = {0, 0};

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      switch (maze[i][j]) {
      case 1:
        redPos       = pos(i, j);
        redChk[i][j] = true;
        break;
      case 2:
        bluePos       = pos(i, j);
        blueChk[i][j] = true;
        break;
      case 3:
        redDest = pos(i, j);
        break;
      case 4:
        blueDest = pos(i, j);
        break;
      }
    }
  }
  int answer = 0;

  queue<state> q;
  q.push(state(redPos, bluePos, redChk, blueChk, answer));
  while (!q.empty()) {
    state cur = q.front();
    q.pop();
    pos                  rp = cur.redPos;
    pos                  bp = cur.bluePos;
    vector<vector<bool>> rc = cur.redChk;
    vector<vector<bool>> bc = cur.blueChk;

    if (maze[rp.r][rp.c] == 3 && maze[bp.r][bp.c] == 4) {
      answer = cur.moves;
      break;
    }

    for (int i = 0; i < 4; i++) {

      int                  nrR = rp.r + dr[i];
      int                  ncR = rp.c + dc[i];
      vector<vector<bool>> nrc = rc;

      if (maze[rp.r][rp.c] == 3) {
        nrR = rp.r;
        ncR = rp.c;
      } else {
        if (nrR < 0 || nrR >= R || ncR < 0 || ncR >= C)
          continue; // out of bounds
        if (maze[nrR][ncR] == 5)
          continue; // wall
        if (rc[nrR][ncR])
          continue; // already visited

        nrc[nrR][ncR] = true;
      }

      for (int j = 0; j < 4; j++) {
        int                  nrB = bp.r + dr[j];
        int                  ncB = bp.c + dc[j];
        vector<vector<bool>> nbc = bc;

        if (maze[bp.r][bp.c] == 4) {
          nrB = bp.r;
          ncB = bp.c;
        } else {
          if (nrB < 0 || nrB >= R || ncB < 0 || ncB >= C)
            continue; // out of bounds
          if (maze[nrB][ncB] == 5)
            continue; // wall
          if (bc[nrB][ncB])
            continue; // already visited

          nbc[nrB][ncB] = true;
        }
        if (nrR == nrB && ncR == ncB)
          continue; // no same slot
        if (nrR == bp.r && ncR == bp.c && nrB == rp.r && ncB == rp.c)
          continue; // no crossing
        q.push(state(pos(nrR, ncR), pos(nrB, ncB), nrc, nbc, cur.moves + 1));
      }
    }
  }

  return (answer);
}
