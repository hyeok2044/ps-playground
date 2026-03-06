#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdio.h>

using namespace std;
#define WIDTH (8)

int currentTiles[WIDTH][WIDTH];
int nextTiles[10000][WIDTH];
int matches[WIDTH][WIDTH];

// 0 ~ 8
int scores[9] = {0, 0, 0, 1, 4, 9, 9, 9, 9};

// fetch from next. Start from zero.
int nextRows[WIDTH];

void fillGaps()
{
  for (int i = WIDTH - 1; i >= 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      if (currentTiles[i][j])
        continue;
      currentTiles[i][j] = nextTiles[nextRows[j]++][j];
    }
  }
}

void fallThrough()
{
  for (int i = WIDTH - 1; i >= 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      if (currentTiles[i][j])
        continue;

      for (int k = i - 1; k >= 0; k--) {
        if (!currentTiles[k][j])
          continue;
        currentTiles[i][j] = currentTiles[k][j];
        currentTiles[k][j] = 0;
        break;
      }
    }
  }

  fillGaps();
}

void clearField()
{
  for (int i = WIDTH - 1; i >= 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      currentTiles[i][j] = 0;
    }
  }

  fillGaps();
}

void clearMatches()
{

  for (int i = WIDTH - 1; i >= 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      if (matches[i][j]) {
        currentTiles[i][j] = 0;
      }
    }
  }

  fallThrough();
}

bool scanMatches()
{

  bool chk = false;
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      matches[i][j] = 0;
    }
  }

  for (int i = WIDTH - 1; i >= 0; i--) {
    int prev = 0;
    int cnt  = 0;
    for (int j = 0; j < WIDTH; j++) {
      int cur = currentTiles[i][j];
      if (cur == prev) {
        cnt++;
      } else {
        prev = cur;
        cnt  = 1;
      }

      if (cnt == 3) {
        matches[i][j - 2] = 1;
        matches[i][j - 1] = 1;
      }

      if (cnt >= 3) {
        matches[i][j] = 1;
        chk           = true;
      }
    }
  }

  for (int i = 0; i < WIDTH; i++) {
    int prev = 0;
    int cnt  = 0;
    for (int j = WIDTH - 1; j >= 0; j--) {
      int cur = currentTiles[j][i];
      if (cur == prev) {
        cnt++;
      } else {
        prev = cur;
        cnt  = 1;
      }

      if (cnt == 3) {
        matches[j + 2][i] = 1;
        matches[j + 1][i] = 1;
      }

      if (cnt >= 3) {
        matches[j][i] = 1;
        chk           = true;
      }
    }
  }

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      // cout << matches[i][j] << " ";
    }
    // cout << endl;
  }

  return chk;
}

int calcScore()
{

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      matches[i][j] = 0;
    }
  }

  int score = 0;
  for (int i = WIDTH - 1; i >= 0; i--) {
    int prev = 0;
    int cnt  = 0;
    for (int j = 0; j < WIDTH; j++) {
      int cur = currentTiles[i][j];
      if (cur == prev) {
        cnt++;
      } else {
        score += scores[cnt];
        prev = cur;
        cnt  = 1;
      }

      if (cnt == 3) {
        matches[i][j - 2] = 1;
        matches[i][j - 1] = 1;
      }

      if (cnt >= 3) {
        matches[i][j] = 1;
      }
    }
    score += scores[cnt];
  }

  for (int i = 0; i < WIDTH; i++) {
    int prev = 0;
    int cnt  = 0;
    for (int j = WIDTH - 1; j >= 0; j--) {
      int cur = currentTiles[j][i];
      if (cur == prev) {
        cnt++;
      } else {
        score += scores[cnt];
        prev = cur;
        cnt  = 1;
      }

      if (cnt == 3) {
        matches[j + 2][i] = 1;
        matches[j + 1][i] = 1;
      }

      if (cnt >= 3) {
        matches[j][i] = 1;
      }
    }

    score += scores[cnt];
  }
  return score;
}

int  ret[5];
void clearSwap()
{
  int mxmScore = 0;
  int r        = 0;
  int c        = 0;
  int nr       = 0;
  int nc       = 0;

  int direction = 0;
  while (true) {

    // also do the clearing too.
    bool b = scanMatches();
    while (b) {
      clearMatches();
      b = scanMatches();
      // cout << "match found" << endl;
    }

    for (int i = WIDTH - 1; i >= 0; i--) {
      for (int j = 0; j < WIDTH; j++) {
        // swap right
        if (j + 1 < WIDTH) {
          int tmp                = currentTiles[i][j];
          currentTiles[i][j]     = currentTiles[i][j + 1];
          currentTiles[i][j + 1] = tmp;
          int score              = calcScore();
          if (mxmScore < score) {
            mxmScore = score;
            r        = i;
            c        = j;
            nr       = i;
            nc       = j + 1;
          }
          tmp                    = currentTiles[i][j];
          currentTiles[i][j]     = currentTiles[i][j + 1];
          currentTiles[i][j + 1] = tmp;
        }
        // swap up

        if (i - 1 >= 0) {
          int tmp                = currentTiles[i][j];
          currentTiles[i][j]     = currentTiles[i - 1][j];
          currentTiles[i - 1][j] = tmp;
          int score              = calcScore();
          if (mxmScore < score) {
            mxmScore = score;
            r        = i;
            c        = j;
            nr       = i - 1;
            nc       = j;
          }
          tmp                    = currentTiles[i][j];
          currentTiles[i][j]     = currentTiles[i - 1][j];
          currentTiles[i - 1][j] = tmp;
        }
      }
    }

    if (mxmScore != 0) {
      break;
    }

    clearField();

    // cout << "Could not find. Clearing the field" << endl;
  }
  ret[0] = mxmScore;
  ret[1] = r;
  ret[2] = c;
  ret[3] = nr;
  ret[4] = nc;
  // cout << "Mxm Score can be achieved from swapping (" << r << " " << c << "),
  // ("
  //<< nr << " " << nc << ") +" << mxmScore << endl;
}

void init(int N, int mTiles[][WIDTH])
{

  for (int i = 0; i < WIDTH; i++) {
    nextRows[i] = 0;
  }

  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      currentTiles[i][j] = 0;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < WIDTH; j++) {
      nextTiles[i][j] = mTiles[i][j];
    }
  }

  // 1-a
  fillGaps();

  for (int i = WIDTH - 1; i >= 0; i--) {
    for (int j = 0; j < WIDTH; j++) {
      // cout << nextTiles[nextRows[j] + i][j] << " ";
    }
    // cout << endl;
  }
  for (int i = 0; i < WIDTH; i++) {
    for (int j = 0; j < WIDTH; j++) {
      // cout << currentTiles[i][j] << " ";
    }
    // cout << endl;
  }

  // cout << endl;

  // 1-c
}

int  mRet[5];
int *takeTurn()
{
  clearSwap();

  int tmp                      = currentTiles[ret[1]][ret[2]];
  currentTiles[ret[1]][ret[2]] = currentTiles[ret[3]][ret[4]];
  currentTiles[ret[3]][ret[4]] = tmp;

  int score = 0;
  int sc    = calcScore();
  while (sc > 0) {
    score += sc;
    clearMatches();
    sc = calcScore();
  }

  mRet[0] = score;
  mRet[1] = WIDTH - 1 - ret[1];
  mRet[2] = ret[2];
  mRet[3] = WIDTH - 1 - ret[3];
  mRet[4] = ret[4];
  return mRet;
}

const int CMD_INIT     = 100;
const int CMD_TAKETURN = 200;

static int tiles[10000][WIDTH];

extern void init(int N, int mTiles[][WIDTH]);
extern int *takeTurn();

static bool run()
{
  bool okay = false;
  int  Q, N;

  scanf("%d", &Q);

  for (int q = 0; q < Q; ++q) {
    int  cmd;
    int  correct_ans[5];
    int *user_ans;
    scanf("%d", &cmd);
    switch (cmd) {
    case CMD_INIT:
      scanf("%d", &N);
      for (int y = 0; y < N; y++) {
        for (int x = 0; x < WIDTH; x++) {
          scanf("%d", tiles[y] + x);
        }
      }

      init(N, tiles);
      okay = true;
      break;
    case CMD_TAKETURN:
      user_ans = takeTurn();
      for (int i = 0; i < 5; i++) {
        scanf("%d", correct_ans + i);
        if (user_ans[i] != correct_ans[i])
          okay = false;
      }
      break;
    default:
      okay = false;
      break;
    }
  }

  return okay;
}

int main()
{
  setbuf(stdout, NULL);
  //	freopen("sample_input.txt", "r", stdin);

  int TC, MARK;

  scanf("%d %d", &TC, &MARK);
  for (int tc = 1; tc <= TC; ++tc) {
    int score = run() ? MARK : 0;
    printf("#%d %d\n", tc, score);
  }

  return 0;
}
