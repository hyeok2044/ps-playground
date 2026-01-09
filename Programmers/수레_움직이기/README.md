# 봉인된 주문

Solved at: 2026-01-09 (90m)

https://school.programmers.co.kr/learn/courses/30/lessons/250134

Simulation

I should've read the question carefully.

### Difficult condition

Since both of them are moving at the same time, we should not really consider
the order.

- BOTH of the wagons should move unless one has arrived.

- Swapping is not allowed.

  ```
  if (nrR == nrB && ncR == ncB)
    continue; // no same slot

  if (nrR == bp.r && ncR == bp.c && nrB == rp.r && ncB == rp.c)
    continue; // no crossing
  ```
