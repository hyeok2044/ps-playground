#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> nodes, vector<vector<int>> edges)
{
  // Every nodes should only have one parent.
  bool nodeChk[1000001];
  for (int i = 0; i <= 1000000; i++)
    nodeChk[i] = false;
  for (int i : nodes) {
    nodeChk[i] = true;
  }

  int edgesCnt[1000001];
  for (int i = 0; i <= 1000000; i++)
    edgesCnt[i] = 0;

  vector<int> realEdges[1000001];
  for (vector v : edges) {
    realEdges[v[0]].push_back(v[1]);
    realEdges[v[1]].push_back(v[0]);
    edgesCnt[v[0]]++;
    edgesCnt[v[1]]++;
  }

  vector<vector<int>> trees;
  for (int i : nodes) {
    if (!nodeChk[i])
      continue;
    vector<int> tree;
    queue<int>  q;
    q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      nodeChk[cur] = false;
      tree.push_back(cur);
      for (int i : realEdges[cur]) {
        if (nodeChk[i]) {
          q.push(i);
        }
      }
    }
    trees.push_back(tree);
  }
  // trees currently contain the forest.
  // realEdges contain the edges.

  int trueOrderTreeCnt = 0;
  int revOrderTreeCnt  = 0;

  for (vector<int> tr : trees) {
    if (tr.size() == 1) {
      if (tr[0] % 2 == 0)
        trueOrderTreeCnt++;
      else
        revOrderTreeCnt++;
      continue;
    }
    int totalCnt   = tr.size();
    int unMatchCnt = 0;
    for (int i : tr) {
      int oddity     = i % 2;
      int edgeOddity = edgesCnt[i] % 2;
      // match = 0^0 or 1^1 -> 0, unmatch: 0^1 -> 1
      unMatchCnt += (oddity ^ edgeOddity);
    }

    if (unMatchCnt == 1)
      revOrderTreeCnt++;
    if (totalCnt - unMatchCnt == 1)
      trueOrderTreeCnt++;
  }

  vector<int> answer = {trueOrderTreeCnt, revOrderTreeCnt};
  return answer;
}
