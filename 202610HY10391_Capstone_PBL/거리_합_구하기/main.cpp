#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

int n;

vector<pair<int, ll>> tree[200001];

int cnt_ch[200001];
ll  ans[200001];

pair<int, ll> dfs(int prev, int cur)
{
  pair<int, ll> res = {1, 0};
  for (auto np : tree[cur]) {
    int nxt = np.first;
    if (nxt == prev)
      continue;
    auto dfs_res = dfs(cur, nxt);
    res.first += dfs_res.first;
    res.second += np.second * dfs_res.first;
    res.second += dfs_res.second;
  }
  cnt_ch[cur] = res.first;
  return res;
}

void dfs2(int prev, int cur)
{
  for (auto np : tree[cur]) {
    int nxt = np.first;
    if (nxt == prev)
      continue;
    int sz   = cnt_ch[nxt];
    ans[nxt] = ans[cur] + np.second * (n - 2 * sz);
    dfs2(cur, nxt);
  }
}

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    ll  t;
    cin >> a >> b >> t;
    tree[a].emplace_back(b, t);
    tree[b].emplace_back(a, t);
  }

  auto a = dfs(1, 1);
  ans[1] = a.second;
  dfs2(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << endl;
  }
}
