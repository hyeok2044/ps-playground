#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-01-14 07:42 ~ 07:58
// 25186 Overall Ranking

// sorting

class univ
{
public:
  int    rankSum;
  int    num;
  string name;
  univ(int a, int b, string c) : rankSum(a), num(b), name(c){};
};

bool comp(univ a, univ b)
{
  return a.rankSum * b.num < b.rankSum * a.num;
}

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  cin.ignore();
  vector<univ> vec;

  unordered_map<string, int> um;
  for (int i = 1; i <= n; i++) {
    string str;
    getline(cin, str);
    if (um.find(str) == um.end()) {
      um[str] = (int)vec.size();
      vec.emplace_back(i, 1, str);
    } else {
      univ &cur = vec[um[str]];
      cur.num++;
      cur.rankSum += i;
    }
  }
  sort(vec.begin(), vec.end(), comp);
  for (univ uni : vec) {
    cout << uni.name << endl;
  }
}
