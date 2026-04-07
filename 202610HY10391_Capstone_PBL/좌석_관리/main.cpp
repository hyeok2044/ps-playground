#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 0: not assigned 1: seated 2: out
int eaten[10001];
int seats[21][21];

int getDistSquared(int x1, int y1, int x2, int y2)
{
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

pair<int, int> returnSeat(int n, int m, int id)
{
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (seats[i][j] == id) {
        return {i, j};
      }
    }
  }
  return {0, 0};
}

pair<int, int> seekForSeat(int n, int m)
{
  int x = 0, y = 0, dist = 0;

  for (int x1 = 1; x1 <= n; x1++) {
    for (int y1 = 1; y1 <= m; y1++) {
      if (seats[x1][y1] != 0)
        continue;
      int curDist = 1e9;
      for (int x2 = 1; x2 <= n; x2++) {
        for (int y2 = 1; y2 <= m; y2++) {
          if (seats[x2][y2] != 0) {
            curDist = min(curDist, getDistSquared(x1, y1, x2, y2));
          }
        }
      }
      if (curDist > dist) {
        dist = curDist;
        x    = x1;
        y    = y1;
      }
    }
  }
  if (dist == 1) {
    return {0, 0};
  }
  return {x, y};
}

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, q;
  cin >> n >> m >> q;
  for (int t = 0; t < q; t++) {
    string s;
    int    id;
    cin >> s >> id;
    if (s == "In") {
      if (eaten[id] == 0) {
        auto p = seekForSeat(n, m);
        if (p.first == 0) {
          cout << "There are no more seats." << endl;
        } else {
          cout << id << " gets the seat (" << p.first << ", " << p.second
               << ")." << endl;
          eaten[id]                = 1;
          seats[p.first][p.second] = id;
        }
      } else if (eaten[id] == 1) {
        cout << id << " already seated." << endl;
      } else {
        cout << id << " already ate lunch." << endl;
      }
    } else {
      if (eaten[id] == 0) {
        cout << id << " didn't eat lunch." << endl;
      } else if (eaten[id] == 1) {
        auto p = returnSeat(n, m, id);
        cout << id << " leaves from the seat (" << p.first << ", " << p.second
             << ")." << endl;
        seats[p.first][p.second] = 0;
        eaten[id]                = 2;
      } else {
        cout << id << " already left seat." << endl;
      }
    }
  }
}
