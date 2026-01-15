#include <string>

using namespace std;

// 2026-01-16 04:37 ~ 05:02
// d -> l -> r -> u
// greedy.
// as much down as possible -> as much left as possible.
// construct optimal path first.

string solution(int n, int m, int x, int y, int r, int c, int k)
{
  int    cnt    = 0;
  string answer = "";
  int    xx = x, yy = y;
  while (xx < r) {
    cnt++;
    xx++;
  }

  while (yy > c) {
    cnt++;
    yy--;
  }

  while (yy < c) {
    cnt++;
    yy++;
  }

  while (xx > r) {
    cnt++;
    xx--;
  }

  if (cnt > k) {
    return "impossible";
  }

  if ((cnt % 2) != (k % 2)) {
    return "impossible";
  }

  xx = x;
  yy = y;

  while (xx < r) {
    answer += 'd';
    xx++;
  }

  while (cnt + 2 <= k && xx + 1 <= n) {
    answer += 'd';
    xx++;
    cnt += 2;
  }

  while (yy > c) {
    answer += 'l';
    yy--;
  }

  while (cnt + 2 <= k && yy - 1 >= 1) {
    answer += 'l';
    yy--;
    cnt += 2;
  }

  while (cnt + 2 <= k) {
    answer += "rl";
    cnt += 2;
  }

  while (yy < c) {
    answer += 'r';
    yy++;
  }

  while (xx > r) {
    answer += 'u';
    xx--;
  }
  return answer;
}
