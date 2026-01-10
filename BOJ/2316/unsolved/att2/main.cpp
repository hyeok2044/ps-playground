#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 2316
/* attempt 2: dinic
 * what is a maximum flow from 1 to 2?
 * + vertex splitting
 * Dinic:
 * 1. make a level graph
 */

int levels[401];

struct edge {
  int to;
  int rev;
  int cap;
};

vector<edge> edges[401];

int main(void)
{

  int n, p;
  cin >> n >> p;
  for (int i = 0; i < p; i++) {
    int a, b;
    cin >> a >> b;
    // a -> b
    edges[a].push_back({b, (int)edges[b].size(), 1});
    edges[b].push_back({a, (int)edges[a].size() - 1, 0});

    // b -> a
    edges[b].push_back({a, (int)edges[a].size(), 1});
    edges[a].push_back({b, (int)edges[b].size() - 1, 0});
  }
  int source = 1;
  int sink   = 2;

  while (true) {
    // bfs
    queue<int> q;
    q.push(source);
    for (int i = 1; i <= n; i++) {
      levels[i] = 123456789;
    }
    levels[source] = 0;
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (edge e : edges[cur]) {
        if (e.cap > 0 && levels[e.to] > levels[cur] + 1) {
          levels[e.to] = levels[cur] + 1;
          q.push(e.to);
        }
      }
    }

    // dfs
    stack<int> st;
    st.push(source);
    while (!st.empty()) {
      int cur = st.top();
      st.pop();
      for (edge e : edges[cur]) {
        if (e.cap > 0 && levels[cur] + 1 == levels[e.to]) {
        }
      }
    }
  }
}
