#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef long long int ll;

ll stringToNumber(string s)
{
  // aa -> 26 + 1 aba 26^2 + 26*2 + 1
  ll res = 0;
  for (int i = 0; i < s.length(); i++) {
    res *= 26;
    res += s[i] - 'a' + 1;
  }
  return res;
}

string numberToString(ll n)
{
  string s;
  while (n > 0) {
    if (n % 26 == 0) {
      s += 'z';
      n -= 26;
    } else {
      s += (char)((n % 26) - 1 + 'a');
      n -= n % 26;
    }
    n /= 26;
  }
  reverse(s.begin(), s.end());
  return s;
}

string solution(long long n, vector<string> bans)
{
  vector<ll> vec;
  for (string s : bans)
    vec.push_back(stringToNumber(s));
  sort(vec.begin(), vec.end());
  ll ans = n;
  for (ll k : vec) {
    if (ans >= k) {
      ans++;
    }
  }
  string answer = numberToString(ans);
  return answer;
}
