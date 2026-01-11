#include <algorithm>
#include <vector>

using namespace std;

// 2026-01-10 09:38 ~ 11:00 (failed)
// 2026-01-11 09:40 ~ 09:45

int solution(vector<vector<int>> scores)
{
  vector<int>            vec;
  vector<pair<int, int>> pairs;

  for (auto s : scores) {
    pairs.emplace_back(s[0], s[1]);
  }

  sort(pairs.begin(), pairs.end(), greater<pair<int, int>>());
  int pivota = 123456789, pivotb = 0, prevPivotb = 0;
  for (auto p : pairs) {
    if (p.first < pivota) {
      if (p.second >= pivotb) {
        pivota     = p.first;
        prevPivotb = pivotb;
        pivotb     = p.second; // case 1, 3-b
        vec.emplace_back(p.first + p.second);
      } else {
        // case 2: do nothing
        if (p.first == scores[0][0] && p.second == scores[0][1]) {
          return -1; // wanho is not the candidate.
        }
      }
    } else {
      if (p.second >= prevPivotb) {
        vec.emplace_back(p.first + p.second);
      }
      // case 3-a
    }
  }
  int answer = 1;
  for (int v : vec) {
    // how many are above me?
    if (v > scores[0][0] + scores[0][1])
      answer++;
  }
  return answer;
}
