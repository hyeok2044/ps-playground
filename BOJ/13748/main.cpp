#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 13748
// 2026-01-10 08:40 ~ 08:54

string nextStr(string s, int n)
{
  string ret;
  ret += s[n - 1];
  for (int i = 0; i < n - 1; i++) {
    ret += s[i];
  }
  return ret;
}

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int n   = (int)s.length();
  int ans = n;
  for (int i = n - 1; i >= 1; i--) {
    if (n % i != 0)
      continue;
    vector<string> vec;
    string         tmp;
    int            idx = 0;
    while (idx < n) {
      tmp += s[idx];
      if (idx % i == i - 1) {
        vec.push_back(tmp);
        tmp = "";
      }
      idx++;
    }
    string comp = vec[0];
    bool   chk  = true;
    for (string tmp : vec) {
      if (tmp != comp) {
        chk = false;
        break;
      }
      comp = nextStr(comp, i);
    }
    if (chk)
      ans = i;
  }
  cout << ans << endl;
}
