#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    vector<int> services;
    int         n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      services.push_back(a);
    }
    priority_queue<int> pq;
    pq.push(0);
    sort(services.begin(), services.end());
    for (int i = n - 1; i >= 0; i--) {
      int cur = pq.top();
      if (cur >= services[i]) {
        pq.pop();
        pq.push(cur - services[i]);
      } else {
        pq.push(900 - services[i]);
      }
    }
    cout << pq.size() - 1 << endl;
  }
}
