#include <vector>

using namespace std;

// 2026-01-17 09:11
// (20 - 5) H 5 is small enough
// We can make all the possible combinations.
int         arr[5];
int         maxDepth;
int         mnm = 123456789;
vector<int> vec(20);

void interview(const vector<vector<int>> &reqs)
{
  int cost = 0;
  for (int i = 0; i < maxDepth; i++) {
    int t = 0;
    for (int j = 0; j < arr[i]; j++) {
      vec[j] = 0;
    }
    for (auto req : reqs) {
      if (req[2] != i + 1) {
        continue;
      }

      int minIdx = 0;
      int t      = 123456789;

      for (int j = 0; j < arr[i]; j++) {
        if (vec[j] < t) {
          t      = vec[j];
          minIdx = j;
        }
      }
      if (t <= req[0]) {
        vec[minIdx] = req[0] + req[1];
      } else {
        cost += t - req[0];
        vec[minIdx] = t + req[1];
      }
    }
  }
  mnm = min(mnm, cost);
}
void solve(int depth, int remainder, const vector<vector<int>> &reqs)
{
  if (depth == maxDepth) {
    interview(reqs);
    return;
  }
  if (depth == maxDepth - 1) {
    arr[depth] = remainder + 1;
    solve(depth + 1, 0, reqs);
    return;
  }
  for (int i = 0; i <= remainder; i++) {
    arr[depth] = i + 1;
    solve(depth + 1, remainder - i, reqs);
  }
}

int solution(int k, int n, vector<vector<int>> reqs)
{
  maxDepth = k;
  solve(0, n - k, reqs);
  int answer = mnm;
  return answer;
}
