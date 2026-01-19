# 고고학 최고의 발견

Solved at: 2026-01-20 (30m)

https://school.programmers.co.kr/learn/courses/30/lessons/131702

Greedy

1. If rotation of the top row is determined, other rows are automatically determined.
   - Given that the row is finished, one node can only be affected by its bottom node.

2. There are only 4 feasible rotations $(0 ~ 3)$ for each nodes.
   - Therefore, we can calculate all the possible rotations of the top rows by
     iterating through $O(4^n)$ cases.
