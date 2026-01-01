#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

/*
 * A -> B, B -> C,  C -> D -> ...
 * 1. mapping
 * 2. calculate indegree, outdegree
 *    if indegree = 1, start from there.
 */
vector<pair<string, string>> iten;

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    iten.clear();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string from, to;
      cin >> from >> to;
      iten.push_back({from, to});
    }

    int order[n];
    // starter
    int starter = 0;
    for (int i = 0; i < n; i++) {
      bool   chk  = true;
      string from = iten[i].first;
      for (int j = 0; j < n; j++) {
        if (iten[j].second == from) {
          chk = false;
          break;
        }
      }
      if (chk) {
        starter = i;
        break;
      }
    }

    order[0] = starter;

    int cur = starter;
    // finding
    for (int i = 1; i < n; i++) {
      string to = iten[cur].second;
      for (int j = 0; j < n; j++) {
        if (iten[j].first == to) {
          order[i] = j;
          cur      = j;
          break;
        }
      }
    }

    cout << "Case #" << t << ": ";
    for (int i = 0; i < n; i++) {
      cout << iten[order[i]].first << "-" << iten[order[i]].second << " ";
    }
    cout << endl;
  }
}
