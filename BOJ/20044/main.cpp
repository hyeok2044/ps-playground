#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

/*
 * Greedy: sort and match.
 */

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> vec;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vec.push_back(a);
    vec.push_back(b);
  }
  sort(vec.begin(), vec.end());
  int front = 0, back = vec.size() - 1;
  int ans = 0x7fffffff;
  while (front < back) {
    ans = min(ans, vec[front++] + vec[back--]);
  }
  cout << ans << endl;
}
