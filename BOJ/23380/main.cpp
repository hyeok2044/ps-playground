#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

// 23380
// 2026-01-10 07:34 ~ 07:44
// Sort by pair and team up.

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec.push_back({a, b});
  }
  sort(vec.begin(), vec.end());
  int bill = vec[0].first + vec[vec.size() - 1].first;
  int pool = vec[0].second + vec[vec.size() - 1].second;

  bool chk = true;
  for (int i = 0; i < n; i++) {
    int b1 = vec[i].first + vec[n - i - 1].first;
    int p1 = vec[i].second + vec[n - i - 1].second;
    if (b1 != bill || p1 != pool)
      chk = false;
  }

  if (n % 2 != 0) {
    chk = false; // odd number: we cannot divide them into two.
  }

  if (chk) {
    cout << "possible" << endl;
  } else {
    cout << "impossible" << endl;
  }
}
