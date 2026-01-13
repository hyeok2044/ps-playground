#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long int ll;

// 2026-01-13 08:43 ~ 09:13
// Q: Does my subtree exist when i am zero?

bool solve(string s)
{
  int n = (int)s.length();

  int root = n / 2;
  // 1: 0, 3: 1, 7: 3 -> /2.
  if (n == 1)
    return true;
  string sub1 = s.substr(0, root);
  string sub2 = s.substr(root + 1, root);
  if (s[root] == '0') {
    for (char c : sub1)
      if (c == '1')
        return false;
    for (char c : sub2)
      if (c == '1')
        return false;
  }
  return solve(sub1) && solve(sub2);
}

string numToString(ll num)
{
  int limit = 1;

  // check for the string digits
  while (num > ((1ll << limit) - 1)) {
    limit = limit * 2 + 1;
  }
  string ret = "";
  for (int i = 0; i < limit; i++) {
    if (num % 2 == 0) {
      ret += "0";
    } else {
      ret += "1";
    }
    num /= 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

vector<int> solution(vector<long long> numbers)
{
  vector<int> answer;
  for (ll i : numbers) {
    answer.emplace_back(solve(numToString(i)));
  }
  return answer;
}
