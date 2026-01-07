#include <set>
#include <vector>

using namespace std;
// 2026-01-07 11:00 1hr fail.
// 2026-01-07 12:40 20m after solution.

int solution(int coin, vector<int> cards)
{

  set<int> hands;
  set<int> picks;
  int      n     = cards.size();
  int      initN = n / 3;
  for (int i = 0; i < initN; i++)
    hands.insert(cards[i]);
  int round = 1;
  for (int index = initN; index < n; index += 2) {
    picks.insert(cards[index]);
    picks.insert(cards[index + 1]);
    bool chk = false;

    // no coin used.
    for (auto it = hands.begin(); it != hands.end(); it++) {
      if (hands.find(n + 1 - *it) != hands.end()) {
        hands.erase(n + 1 - *it);
        hands.erase(*it);
        round++;
        chk = true;
        break;
      }
    }
    if (chk)
      continue;

    // one coin used.
    if (coin <= 0)
      break;
    for (auto it = hands.begin(); it != hands.end(); it++) {
      if (picks.find(n + 1 - *it) != picks.end()) {
        coin--;
        picks.erase(n + 1 - *it);
        hands.erase(*it);
        round++;
        chk = true;
        break;
      }
    }
    if (chk)
      continue;

    // two coins used.
    if (coin <= 1)
      break;
    for (auto it = picks.begin(); it != picks.end(); it++) {
      if (picks.find(n + 1 - *it) != picks.end()) {
        coin -= 2;
        picks.erase(n + 1 - *it);
        picks.erase(*it);
        round++;
        chk = true;
        break;
      }
    }
    if (chk)
      continue;
    break;
  }
  return round;
}
