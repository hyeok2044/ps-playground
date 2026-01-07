#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
// 2026-01-07 11:00 1hr fail.

// card is a permutation. n + 1 - k -> k's complement.

// [10 7 6 11 12 3 8 4 5 1 2 9] required

//    1        5         10
// [X 4 3 0 11 6 1 2 8 7 5 10 9] position of each elem

//  2 1 1      2  |
// [5 2 1 10 9 0 8 11 6 4 3 7] position of required

// greedy?

// where is the pair's last location?
// (2, 1), (5, 0), (9, 4), (10, 3), (8, 6), (11, 7)
// 0 0 1 0 1 1 1 0 -> number of submittable pairs.

int solution(int coin, vector<int> cards)
{
  int         n = cards.size();
  vector<int> required;
  for (int i : cards) {
    required.push_back(n + 1 - i);
  }

  vector<int> positionOfElems(n + 1);
  for (int i = 0; i < n; i++) {
    positionOfElems[cards[i]] = i;
  }

  vector<int> positionOfRequired;
  for (int i : required) {
    positionOfRequired.push_back(positionOfElems[i]);
  }

  vector<pair<int, int>> comp;
  for (int i = 0; i < n; i++) {
    if (positionOfRequired[i] > i) {
      comp.push_back({i, positionOfRequired[i]});
    }
  }

  sort(comp.begin(), comp.end());
  vector<bool> chk(comp.size(), false);
  int          initPiles = n / 3;
  int          answer    = 1;

  for (int i = 0; i < comp.size(); i++) {
    for (int j = 0; j < comp.size(); j++) {
      if (chk[j])
        continue;
      auto ord = comp[j];
      if (ord.first >= initPiles || ord.second >= initPiles) {
        continue;
      }

      if (coin >= 0) {
        answer++;
        chk[j] = true;
      }
    }
  }

  for (int i = 0; i < comp.size(); i++) {
    for (int j = 0; j < comp.size(); j++) {
      if (chk[j])
        continue;
      auto ord = comp[j];
      if (ord.second >= initPiles + answer * 2)
        continue;
      if (ord.first >= initPiles && ord.second >= initPiles) {
        continue;
      }
      if (ord.first >= initPiles) {
        coin--;
      }
      if (ord.second >= initPiles) {
        coin--;
      }

      if (coin >= 0) {
        answer++;
        chk[j] = true;
      } else {
        if (ord.first >= initPiles) {
          coin++;
        }
        if (ord.second >= initPiles) {
          coin++;
        }
      }
    }
  }

  for (int i = 0; i < comp.size(); i++) {
    for (int j = 0; j < comp.size(); j++) {
      if (chk[j])
        continue;
      auto ord = comp[j];
      if (ord.second >= initPiles + answer * 2)
        continue;
      if (ord.first >= initPiles) {
        coin--;
      }
      if (ord.second >= initPiles) {
        coin--;
      }

      if (coin >= 0) {
        answer++;
        chk[j] = true;
      } else {
        if (ord.first >= initPiles) {
          coin++;
        }
        if (ord.second >= initPiles) {
          coin++;
        }
      }
    }
  }

  answer = min(answer, initPiles + 1);

  return answer;
}
