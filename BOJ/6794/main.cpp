#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 6794
// 2026-01-10 09:27 ~ 09:32
// 1: 1
// 2: 2, 1
// 3: 3, 2
// 4: 4 3 2
// 5: 5 4 3
// 6: 5 4 3
// 7: 5 4
// 8: 5 4
// 9: 5
// 10: 5

vector<int> answer = {0, 1, 2, 2, 3, 3, 3, 2, 2, 1, 1};

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  cout << answer[n] << endl;
}
