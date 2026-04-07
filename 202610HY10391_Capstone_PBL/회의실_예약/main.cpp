#include <bits/stdc++.h>
#include <string>

using namespace std;

typedef long long int ll;

#define endl '\n'

map<string, int> mp;
vector<string>   rooms;

bool occupancy[51][19];

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    mp[s] = i;
    rooms.push_back(s);
  }
  for (int i = 0; i < m; i++) {
    string s;
    int    a, b;
    cin >> s >> a >> b;
    for (int j = a; j < b; j++) {
      occupancy[mp[s]][j] = true;
    }
  }
  sort(rooms.begin(), rooms.end());
  for (int i = 0; i < n; i++) {
    if (i != 0) {
      cout << "-----" << endl;
    }
    cout << "Room " << rooms[i] << ":" << endl;
    int id = mp[rooms[i]];

    bool empty = true;
    int  start = 0;
    int  end   = 0;
    bool prev  = true;

    vector<pair<int, int>> vec;
    for (int j = 9; j <= 17; j++) {
      if (!occupancy[id][j]) {
        empty = false;
        if (prev) {
          start = j;
        }
      } else {
        if (!prev) {
          end = j;
          vec.emplace_back(start, end);
        }
      }
      prev = occupancy[id][j];
    }

    if (!prev) {
      end = 18;
      vec.emplace_back(start, end);
    }

    if (empty) {
      cout << "Not available" << endl;
    } else {
      cout << vec.size() << " available:" << endl;
      for (auto p : vec) {
        string s1 = to_string(p.first);
        string s2 = to_string(p.second);
        if (s1.length() == 1)
          s1 = "09";
        if (s2.length() == 1)
          s2 = "09";
        cout << s1 << "-" << s2 << endl;
      }
    }
  }
}
