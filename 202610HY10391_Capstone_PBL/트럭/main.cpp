#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

#define seonghoon 대성훈

typedef struct Suggestion {
  int user;
  ll  sz;
  ll  pay;
} suggestion;

bool compare(const suggestion &s1, const suggestion &s2)
{
  if (s1.sz == s2.sz) {
    return s1.user < s2.user;
  }
  return s1.sz < s2.sz;
}

vector<ll> q;
vector<ll> q_inv;

ll users[100000];

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int N;
  cin >> N;
  vector<suggestion> vec;
  for (int i = 0; i < N; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 0; j < cnt; j++) {
      ll a, b;
      cin >> a >> b;
      suggestion s = {i, a, b};
      vec.push_back(s);
    }
  }
  sort(vec.begin(), vec.end(), compare);

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    ll tmp;
    cin >> tmp;
    q.push_back(tmp);
  }

  vector<pair<ll, ll>> status;

  ll current_sz   = 0;
  ll current_cost = 0;
  for (suggestion s : vec) {
    if (current_sz < s.sz) {
      status.emplace_back(current_cost, current_sz);
      current_sz = s.sz;
    }

    if (s.pay > users[s.user]) {
      current_cost += s.pay - users[s.user];
      users[s.user] = s.pay;
    }
  }

  status.emplace_back(current_cost, current_sz);
  for (int i = 0; i < q.size(); i++) {
    pair<ll, ll> key = {q[i], 0};
    auto         res = lower_bound(status.begin(), status.end(), key);
    if (res == status.end()) {
      cout << -1 << " ";
    } else {
      cout << res->second << " ";
    }
  }
  cout << endl;
}
