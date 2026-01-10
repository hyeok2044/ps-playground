# 21394

## 숫자 카드

https://www.acmicpc.net/problem/21394

Solved at: 2026-01-10 (15m)

Simulation

1. Since big number is always preferred, convert 6 to 9.

2. Given the number's order, generate a biggest possible string.

   ```
   ex) two 1's and two 9's: 9911

   for (int i = 9; i >= 1; i--) {
     while (cnt[i]--) {
       s += ((char)(i + '0'));
     }
   }
   ```

3. Reverse the process.

- Even index (0, 2, 4th, ...) goes to the left.

- Odd index (1, 3, 5th, ...) goes to the right.

  ```
  vector<char> ans(s.length());
  int          leftIdx = 0, rightIdx = s.length() - 1;
  for (int i = 0; i < s.length(); i++) {
    if (i % 2 == 0) { // first
      ans[leftIdx++] = s[i];
    } else {
      ans[rightIdx--] = s[i];
    }
  }
  ```
