#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-01-14 06:45 ~ 07:20
// 14377 Rank and File (Small)
// Implementation

// every row, increasing ->
// every column increasing (down)
// 2 x N, 1 solder is lost.
// bruteforce from 20, pick 10 as a complete list first.
// 2^20 = 1M

bool comp(vector<int> a, vector<int> b)
{
  return a[0] < b[0];
}

int nums[10][10];
int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);

  int TC;
  cin >> TC;
  for (int tc = 1; tc <= TC; tc++) {
    int n;
    cin >> n;
    vector<vector<int>> vec;
    for (int i = 0; i < 2 * n - 1; i++) {
      vector<int> v;
      for (int j = 0; j < n; j++) {
        int k;
        cin >> k;
        v.push_back(k);
      }
      vec.push_back(v);
    }
    for (int i = 0; i < (1 << (2 * n - 1)); i++) {
      vector<vector<int>> temp;
      vector<vector<int>> temp2;
      if (__builtin_popcount(i) != n) {
        continue;
      }
      for (int j = 0; j < 2 * n - 1; j++) {
        if (i & (1 << j)) {
          temp.push_back(vec[j]);
        } else {
          temp2.push_back(vec[j]);
        }
      }
      sort(temp.begin(), temp.end(), comp);

      for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
          nums[j][k] = temp[j][k];
        }
      }

      int  prev;
      bool notStrictlyIncreasing = false;
      for (int column = 0; column < n; column++) {
        prev = 0;
        for (int row = 0; row < n; row++) {
          if (prev >= nums[row][column]) {
            notStrictlyIncreasing = true;
          }
          prev = nums[row][column];
        }
      }

      if (notStrictlyIncreasing)
        continue;

      vector<bool> occupied(n, false);

      for (vector<int> v : temp2) {
        for (int column = 0; column < n; column++) {
          bool chk = true;
          for (int row = 0; row < n; row++) {
            if (nums[row][column] != v[row]) {
              chk = false;
              break;
            }
          }
          if (chk) {
            occupied[column] = true;
          }
        }
      }

      int cnt = 0;
      int idx = 0;
      for (int j = 0; j < n; j++) {
        if (occupied[j]) {
          cnt++;
        } else {
          idx = j;
        }
      }
      if (cnt != n - 1) {
        continue;
      }
      cout << "Case #" << tc << ": ";
      for (int j = 0; j < n; j++) {
        cout << nums[j][idx] << " ";
      }
      cout << endl;
      break;
    }
  }
}
