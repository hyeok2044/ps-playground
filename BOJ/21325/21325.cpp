#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

/*
 * Tree Structure.
 * DFS. If present, pay and skip.
 *
 */
vector<int> tree[100001];
bool        present[100001];
int         ceo = 0;

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int parent;
    cin >> parent;
    if (parent == 0) {
      ceo = i;
      continue;
    }
    tree[parent].push_back(i);
  }

  for (int i = 0; i < m; i++) {
    int available;
    cin >> available;
    present[available] = true;
  }

  int        ans = 0;
  queue<int> q;
  q.push(ceo);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (present[cur]) {
      ans++;
      continue;
    }
    for (int nxt : tree[cur])
      q.push(nxt);
  }
  cout << ans << endl;
}
