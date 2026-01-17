#include <string>

using namespace std;

// 2026-01-17 18:07 ~
// dp[i][j][k] = ith number, j left k right

int dist[10][10];

pair<int, int> numpad[10] = {
    {3, 1},
    {0, 0},
    {0, 1},
    {0, 2},
    {1, 0},
    {1, 1},
    {1, 2},
    {2, 0},
    {2, 1},
    {2, 2}
};

int getDist(int a, int b)
{
  int dr = abs(numpad[a].first - numpad[b].first);
  int dc = abs(numpad[a].second - numpad[b].second);
  if (dr < dc)
    swap(dr, dc); // dr >= dc
  if (dr == 0)    // insta click
    return 1;
  if (dc == 0) // vertical / horizontal
    return (dr) * 2;
  int diff = dr - dc;
  return dc * 3 + diff * 2;
}

int memo[100001][10][10];

int solution(string numbers)
{
  int answer = 123456789;
  for (int i = 0; i <= numbers.size(); i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        memo[i][j][k] = 123456789;
      }
    }
  }
  memo[0][4][6] = 0;
  for (int i = 0; i < numbers.size(); i++) {
    int num = numbers[i] - '0';
    for (int j = 0; j < 10; j++) {
      // no overlaps
      if (j == num)
        continue;
      for (int k = 0; k < 10; k++) {
        // right hand
        memo[i + 1][j][num] =
            min(memo[i + 1][j][num], memo[i][j][k] + getDist(k, num));
        // left hand
        memo[i + 1][num][j] =
            min(memo[i + 1][num][j], memo[i][k][j] + getDist(k, num));
      }
    }
  }

  int finalNum = numbers[numbers.size() - 1] - '0';
  for (int k = 0; k < 10; k++) {
    answer = min(answer, memo[numbers.size()][finalNum][k]);
    answer = min(answer, memo[numbers.size()][k][finalNum]);
  }
  return answer;
}
