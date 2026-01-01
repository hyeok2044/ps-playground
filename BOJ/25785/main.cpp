#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n';

bool isVowel(char c)
{
  if (c == 'a')
    return true;
  if (c == 'e')
    return true;
  if (c == 'i')
    return true;
  if (c == 'o')
    return true;
  if (c == 'u')
    return true;
  return false;
}

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  bool curStat = isVowel(s[0]);
  bool chk     = true;
  for (size_t i = 1; i < s.length(); i++) {
    if (!(curStat ^ isVowel(s[i]))) {
      chk = false;
    }
    curStat = isVowel(s[i]);
  }
  cout << chk << endl;
}
