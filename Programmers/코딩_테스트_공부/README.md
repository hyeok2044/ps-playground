# 코딩 테스트 공부

Solved at: 2026-01-23 (1h failed)

https://school.programmers.co.kr/learn/courses/30/lessons/118668

Hard.

DP, Dijkstra

## DP

1. Start with alg, cop
   - Had a mistake of setting everything less or equals to that -> incorrect
     solution.

2. Clamping is required.
   - There are some counter examples that prevent magic numbers to deal with.

3. Copying with auto: is not good. use reference instead.

```
alp = 0, cop = 0
problems =
[[0, 0, 30, 2, 1], [0, 150, 0, 0, 1]]

cost = 75
```

## Dijkstra

We can treat each transitions as edges too.
