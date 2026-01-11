#include <algorithm>
#include <vector>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
  if (a.first == b.first)
    return a.second < b.second; // asc
  return a.first > b.first;     // desc
}

int solution(vector<vector<int>> scores)
{
  vector<int>            vec;
  vector<pair<int, int>> pairs;

  for (auto s : scores) {
    pairs.emplace_back(s[0], s[1]);
  }

  sort(pairs.begin(), pairs.end(), comp);
  int pivotb = -1;
  for (auto p : pairs) {
    if (p.second >= pivotb) { // the only case now!
      pivotb = p.second;
      vec.emplace_back(p.first + p.second);
    } else {
      if (p.first == scores[0][0] && p.second == scores[0][1]) {
        return -1; // wanho
      }
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
