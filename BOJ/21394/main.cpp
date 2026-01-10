#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 21394
// 2026-01-10 09:04 ~ 09:20

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int TC;
  cin >> TC;
  while (TC--) {
    vector<int> cnt(10, 0);
    for (int i = 1; i <= 9; i++) {
      int n;
      cin >> n;
      cnt[i] += n;
      if (i == 6) {
        cnt[9] += cnt[6];
        cnt[6] = 0;
      }
    }
    string s;
    for (int i = 9; i >= 1; i--) {
      while (cnt[i]--) {
        s += ((char)(i + '0'));
      }
    }
    vector<char> ans(s.length());
    int          leftIdx = 0, rightIdx = s.length() - 1;
    for (int i = 0; i < s.length(); i++) {
      if (i % 2 == 0) { // first
        ans[leftIdx++] = s[i];
      } else {
        ans[rightIdx--] = s[i];
      }
    }
    for (char c : ans) {
      cout << c << " ";
    }
    cout << endl;
  }
}
