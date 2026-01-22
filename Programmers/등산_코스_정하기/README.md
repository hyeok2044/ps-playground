# 등산 코스 정하기

Solved at: 2026-01-22 (1h)

https://school.programmers.co.kr/learn/courses/30/lessons/118669

Parametric Search + DFS

Difficult problem.

Min-Max Multi-source Dijkstra could be used too.

### Some thoughts

1. I had to sort the summit, since priority is fixed, and summit might not be
   sorted at first.

2. I had an initial idea to use DSU, but this does not work since there is an
   additional condition that summit must be entered only once.

3. Instead of searching everything, since only one summit is available, we can
   logically connect all summits to one, and continue the search.
   - In this code, we did it manually through `dfs()` function, but additional
     edges with source `0`, cost `0` could be added.
