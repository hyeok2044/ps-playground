#include <queue>
#include <vector>

using namespace std;

vector<int> road[100001];

int dist[100001];

// 2026-01-18 13:55 ~ 14:09

vector<int>
solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
  for (auto i : roads) {
    int a = i[0], b = i[1];
    road[a].push_back(b);
    road[b].push_back(a);
  }

  vector<int> answer;
  queue<int>  q;
  for (int i = 1; i <= n; i++) {
    dist[i] = 123456789;
  }
  dist[destination] = 0;
  q.push(destination);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nxt : road[cur]) {
      if (dist[nxt] <= dist[cur])
        continue;
      dist[nxt] = dist[cur] + 1;
      q.push(nxt);
    }
  }
  for (int src : sources) {
    if (dist[src] >= 123456789) {
      answer.push_back(-1);
    } else {
      answer.push_back(dist[src]);
    }
  }

  return answer;
}
