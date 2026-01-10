#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 5366
// 2026-01-10 08:08 ~ 08:18

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  map<string, int> mp;
  vector<string>   order;
  string           s;
  int              sum = 0;
  while (true) {
    getline(cin, s);
    if (s == "0")
      break;
    if (mp[s] == 0) {
      order.push_back(s);
    }
    mp[s]++;
    sum++;
  }
  for (string s : order) {
    cout << s << ": " << mp[s] << endl;
  }
  cout << "Grand Total: " << sum << endl;
}
