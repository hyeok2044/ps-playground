#include <vector>

using namespace std;

// 2026-01-15 09:55
// lower, upper, maintain
// dp?
// time, temperature -> next time, next temperature.
// (if onboard, t1 <= temp <= t2)
// dp[time][temp] = max (dp[time - 1][temp - 1 or +1] + a or b (a if temperature
// > temp)
//                       dp[time - 1][temp]
//                       dp[time - 1][temp + 1 or -1] + b or a )

int tempToIndex(int temperature)
{
  return temperature + 10;
}

int indexToTemp(int index)
{
  return index - 10;
}

int memo[1001][51];

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard)
{
  for (int i = 0; i <= 1000; i++) {
    for (int j = 0; j <= 50; j++) {
      memo[i][j] = 123456789;
    }
  }
  int t      = tempToIndex(temperature);
  memo[0][t] = 0;

  for (int i = 0; i < onboard.size() - 1; i++) {

    if (memo[i][t] < 123456789) {
      if (!(onboard[i + 1] && (t < tempToIndex(t1) || t > tempToIndex(t2)))) {
        memo[i + 1][t] = min(memo[i + 1][t], memo[i][t]);
      }
    }
    // i: previous time, i + 1: current time
    for (int j = 0; j <= 50; j++) {

      // maintain
      if (memo[i][j] < 123456789) {
        if (!(onboard[i + 1] && (j < tempToIndex(t1) || j > tempToIndex(t2)))) {
          memo[i + 1][j] = min(memo[i + 1][j], memo[i][j] + b);
        }
      }

      if (t > j) {
        // temperature is higher
        if (j + 1 <= 50 && memo[i][j] < 123456789) {
          if (!(onboard[i + 1] &&
                (j + 1 < tempToIndex(t1) || j + 1 > tempToIndex(t2)))) {
            memo[i + 1][j + 1] = min(memo[i + 1][j + 1], memo[i][j]);
          }
        }

        if (j - 1 >= 0 && memo[i][j] < 123456789) {
          if (!(onboard[i + 1] &&
                (j - 1 < tempToIndex(t1) || j - 1 > tempToIndex(t2)))) {
            memo[i + 1][j - 1] = min(memo[i + 1][j - 1], memo[i][j] + a);
          }
        }
      } else if (t == j) {

        if (j + 1 <= 50 && memo[i][j] < 123456789) {
          if (!(onboard[i + 1] &&
                (j + 1 < tempToIndex(t1) || j + 1 > tempToIndex(t2)))) {
            memo[i + 1][j + 1] = min(memo[i + 1][j + 1], memo[i][j] + a);
          }
        }

        if (j - 1 >= 0 && memo[i][j] < 123456789) {
          if (!(onboard[i + 1] &&
                (j - 1 < tempToIndex(t1) || j - 1 > tempToIndex(t2)))) {
            memo[i + 1][j - 1] = min(memo[i + 1][j - 1], memo[i][j] + a);
          }
        }
      } else {
        // temperature is lower
        if (j + 1 <= 50 && memo[i][j] < 123456789) {
          if (!(onboard[i + 1] &&
                (j + 1 < tempToIndex(t1) || j + 1 > tempToIndex(t2)))) {
            memo[i + 1][j + 1] = min(memo[i + 1][j + 1], memo[i][j] + a);
          }
        }

        if (j - 1 >= 0 && memo[i][j] < 123456789) {
          if (!(onboard[i + 1] &&
                (j - 1 < tempToIndex(t1) || j - 1 > tempToIndex(t2)))) {
            memo[i + 1][j - 1] = min(memo[i + 1][j - 1], memo[i][j]);
          }
        }
      }
    }
  }
  int answer = 123456789;
  for (int i = 0; i <= 50; i++) {
    answer = min(answer, memo[onboard.size() - 1][i]);
  }
  return answer;
}
