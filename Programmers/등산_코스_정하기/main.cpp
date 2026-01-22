#include <algorithm>
#include <vector>

using namespace std;

vector<int> ss;
bool        summit[50001];
bool        gate[50001];
bool        chk[50001];
int         parent[50001];

vector<pair<int, int>> g[50001];

bool dfs2(int node, int threshold)
{
  if (gate[node]) {
    return true;
  }
  for (auto nxt : g[node]) {
    if (chk[nxt.first]) {
      continue;
    }

    if (nxt.second > threshold) {
      continue;
    }

    chk[nxt.first] = true;
    if (dfs2(nxt.first, threshold)) {
      return true;
    }
  }
  return false;
}

int dfs(int threshold)
{

  for (int s : ss) {
    for (int i = 0; i <= 50000; i++) {
      chk[i] = summit[i];
    }
    chk[s] = false;
    if (dfs2(s, threshold)) {
      return s;
    }
  }
  return -1;
}
vector<int> solution(int                 n,
                     vector<vector<int>> paths,
                     vector<int>         gates,
                     vector<int>         summits)
{
  for (auto p : paths) {
    int i = p[0], j = p[1], w = p[2];
    g[i].emplace_back(j, w);
    g[j].emplace_back(i, w);
  }

  sort(summits.begin(), summits.end());
  for (int i : summits) {
    summit[i] = true;
    ss.push_back(i);
  }

  for (int i : gates) {
    gate[i] = true;
  }
  gate[0] = true;

  int l = 0;
  int r = 2000'0000;

  vector<int> answer(2);
  while (l <= r) {
    int m   = (l + r) / 2;
    int cur = dfs(m);
    if (cur != -1) { // okay
      answer[0] = cur;
      answer[1] = m;
      r         = m - 1;
    } else {
      l = m + 1;
    }
  }

  return answer;
}
