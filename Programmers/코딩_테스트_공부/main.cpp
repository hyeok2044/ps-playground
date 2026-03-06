#include <algorithm>
#include <vector>

using namespace std;

int memo[151][151];

int solution(int alp, int cop, vector<vector<int>> problems)
{
  const int INF = 123456789;

  for (int i = 0; i <= 150; i++) {
    for (int j = 0; j <= 150; j++) {
      memo[i][j] = INF;
    }
  }

  alp            = min(alp, 150);
  cop            = min(cop, 150);
  memo[alp][cop] = 0;

  for (int i = 0; i <= 150; i++) {
    for (int j = 0; j <= 150; j++) {
      if (memo[i][j] == INF)
        continue;

      for (const vector<int> &vec : problems) {
        if (vec[0] > i || vec[1] > j)
          continue;

        int ni = min(150, i + vec[2]);
        int nj = min(150, j + vec[3]);

        memo[ni][nj] = min(memo[ni][nj], memo[i][j] + vec[4]);
      }

      if (i + 1 <= 150) {
        memo[i + 1][j] = min(memo[i + 1][j], memo[i][j] + 1);
      }
      if (j + 1 <= 150) {
        memo[i][j + 1] = min(memo[i][j + 1], memo[i][j] + 1);
      }
    }
  }

  int mx1 = 0, mx2 = 0;
  for (const vector<int> &vec : problems) {
    mx1 = max(mx1, vec[0]);
    mx2 = max(mx2, vec[1]);
  }

  int cost = INF;
  for (int i = mx1; i <= 150; i++) {
    for (int j = mx2; j <= 150; j++) {
      cost = min(cost, memo[i][j]);
    }
  }
  return cost;
}
