# 2차원 동전 뒤집기

Solved at: 2026-01-19 (10m)

https://school.programmers.co.kr/learn/courses/30/lessons/131703

1. XOR the beginning and ending to mark the deltas.

2. We know that flipping one row/column several times can always be translated
   to 0 or 1 flips.

3. Given the deltas, the flipping can be restored by flipping if first element
   is 1 (beginning != end)
   - if this step is done for all rows and columns, but 1 is still left, mark
     it as impossible.

4. flipping every rows, columns makes an equivalent position with different
   number of flips, making this equation: $ans = \min(ans, n + m - ans)$
