#include <vector>

using namespace std;

// 2026-01-06 10:49 ~ 11:15

int cntIndices(int n)
{
  int cnt = 0;
  for (int i = 0; i < 10; i++) {
    if (n & (1 << i))
      cnt++;
  }
  return cnt;
}
vector<int> solution(vector<vector<int>> dice)
{
  vector<int> answer;
  int         n   = dice.size();
  int         mxm = 0;
  for (int i = 0; i < (1 << n); i++) {
    int val = 0;
    if (cntIndices(i) != n / 2)
      continue;

    int aSum[n / 2 + 1][501], bSum[n / 2 + 1][501];
    for (int k = 0; k <= n / 2; k++) {
      for (int j = 0; j <= 500; j++) {
        aSum[k][j] = 0;
        bSum[k][j] = 0;
      }
    }
    aSum[0][0] = 1;
    bSum[0][0] = 1;
    int aBlock = 0, bBlock = 0;
    for (int j = 0; j < n; j++) {     // dice selection
      if (i & (1 << j)) {             // a side
        for (int k = 0; k < 6; k++) { // dice-number selection
          for (int l = 0; l + dice[j][k] <= 500; l++) {
            aSum[aBlock + 1][l + dice[j][k]] += aSum[aBlock][l];
          }
        }
        aBlock++;
      } else {                        // b side
        for (int k = 0; k < 6; k++) { // dice-number selection
          for (int l = 0; l + dice[j][k] <= 500; l++) {
            bSum[bBlock + 1][l + dice[j][k]] += bSum[bBlock][l];
          }
        }
        bBlock++;
      }
    }

    // cumulative sum
    for (int j = 1; j <= 500; j++) {
      bSum[bBlock][j] += bSum[bBlock][j - 1];
    }

    // ex) a is 5 -> beats b from 0 ~ 4
    for (int j = 1; j <= 500; j++) {
      val += aSum[aBlock][j] * bSum[bBlock][j - 1];
    }

    if (val > mxm) {
      answer.clear();
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) > 0) {
          answer.push_back(j + 1);
        }
      }
      mxm = val;
    }
  }
  return answer;
}
