#include <bits/stdc++.h>
#include <queue>

using namespace std;

typedef long long int ll;

#define endl '\n'

ll  totalPackets[100001];
ll  currentPackets[100001];
int inDegree[100001];

vector<int> children[100001];

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  ll  k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int r;
    cin >> r;
    for (int j = 0; j < r; j++) {
      int tmp;
      cin >> tmp;
      children[i].push_back(tmp);
      inDegree[tmp]++;
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
    }
  }
  vector<int> order;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    order.push_back(cur);
    for (int child : children[cur]) {
      inDegree[child]--;
      if (inDegree[child] == 0) {
        q.push(child);
      }
    }
  }

  currentPackets[1] = k;
  for (int cur : order) {
    if (children[cur].size() == 0) {
      continue;
    }
    ll cnt = children[cur].size();
    ll div = currentPackets[cur] / cnt;
    ll rem = currentPackets[cur] % cnt;
    for (int i = 0; i < children[cur].size(); i++) {
      int child = children[cur][i];
      currentPackets[child] += div;
      if (i < rem) {
        totalPackets[child]++;
        currentPackets[child]++;
      }
      q.push(child);
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << currentPackets[i] << " ";
  }
  cout << endl;
}
