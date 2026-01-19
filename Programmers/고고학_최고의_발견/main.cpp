#include <vector>

using namespace std;

// 2026-01-20 01:37 ~ 02:12

int  arr[8][8];
int  n;
int  dr[5] = {-1, 1, 0, 0, 0};
int  dc[5] = {0, 0, -1, 0, 1};
void turn(int r, int c, int cnt)
{
  if (cnt == 0) {
    return;
  }

  for (int i = 0; i < 5; i++) {
    int nr = r + dr[i];
    int nc = c + dc[i];
    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
      arr[nr][nc] += cnt;
      arr[nr][nc] %= 4;
    }
  }
}

int solution(vector<vector<int>> clockHands)
{
  n = clockHands.size();

  int answer = 123456789;
  // 2n, 2n + 1: first row nth element's turns
  for (int i = 0; i < (1 << (n * 2)); i++) {
    int turns = 0;

    for (int r = 0; r < n; r++) {
      for (int c = 0; c < n; c++) {
        arr[r][c] = clockHands[r][c];
      }
    }

    for (int j = 0; j < n; j++) {
      int curTurn = 0;
      if (i & (1 << (2 * j))) {
        curTurn += 1;
      }

      if (i & (1 << (2 * j + 1))) {
        curTurn += 2;
      }
      turns += curTurn;
      turn(0, j, curTurn);
    }

    for (int j = 1; j < n; j++) {
      for (int k = 0; k < n; k++) {
        int nxtTurn = (4 - arr[j - 1][k]) % 4;
        turns += nxtTurn;
        turn(j, k, nxtTurn);
      }
    }
    bool chk = true;
    for (int j = 0; j < n; j++) {
      if (arr[n - 1][j]) {
        chk = false;
      }
    }

    if (!chk) {
      continue;
    }
    answer = min(answer, turns);
  }

  return answer;
}
