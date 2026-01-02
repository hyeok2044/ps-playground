#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 2316
// attempt 1: repetitive bfs
//  Perform bfs, and delete the shortest route from 1 -> 2 everytime.

bool E[401][401];

// {cnt, from, to, available}
int V[401][4];
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n, p;
  cin >> n >> p;

  for (int i = 0; i < p; i++) {
    int a, b;
    cin >> a >> b;
    E[a][b] = true;
    E[b][a] = true;
  }

  int ans = 0;

  for (int i = 0; i < 401; i++) {
    V[i][3] = true;
  }
  while (true) {
    for (int i = 0; i < 401; i++) {
      V[i][0] = 123456789;
    }
    V[1][0] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      for (int i = 1; i <= n; i++) {
        // updated and available
        if (!V[i][3])
          continue;
        if (E[cur][i] && V[i][0] > V[cur][0] + 1) {
          V[i][0] = V[cur][0] + 1;
          V[i][1] = cur;
          V[i][2] = i;
          q.push(i);
        }
      }
    }
    // cannot be reached.
    if (V[2][0] == 123456789) {
      break;
    }
    ans++;
    int curVertex = 2;
    while (curVertex != 1) {
      // clear edges.
      int from = V[curVertex][1];
      int to   = V[curVertex][2];
      assert(to == curVertex);
      E[from][to] = false;
      E[to][from] = false;
      curVertex   = from;

      // make it unavailable.
      if (from != 1)
        V[from][3] = false;
    }
  }
  cout << ans << endl;
}
