# 완전범죄

Solved at: 2026-01-04 (15m)

https://school.programmers.co.kr/learn/courses/30/lessons/389480

2D DP.

Inster
`memo[a][b]` indicates whether it is possible to assign the processed items so that A’s total cost is `a` and B’s total cost is `b`.
For each item, we update the states by assigning it either to A or to B.
After processing all items, we find the minimum a < n such that there exists a valid b < m.
