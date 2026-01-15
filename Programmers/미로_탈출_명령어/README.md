# 미로 탈출 명령어

Solved at: 2026-01-16 (30m)

https://school.programmers.co.kr/learn/courses/30/lessons/150365

Solution Construction, or DFS

## Construction Idea

- Place as many `d` moves as possible **as early as possible**, as long as the move remains **feasible**.
  - After moving down, the remaining Manhattan distance to the target must be ≤ remaining moves.
  - The parity condition must hold: `(remaining_moves - remaining_distance) % 2 == 0`.

- Then, do the same for `l`: place as many `l` moves as possible **as early as possible**, while staying feasible.

- Let `revised = k - dist`. Since `revised` must be even, the extra moves must be consumed by **2-step round trips**.
  - To keep the path lexicographically smallest, avoid round trips involving `u` (`du` / `ud`) if possible.
  - Prefer `rl` / `lr` round trips instead, **as long as the current position allows it** (i.e., you can move right/left without going out of bounds).

- Finally, apply the remaining necessary `r` and `u` moves to reach the target `(r, c)` exactly.
  - Throughout the construction, ensure that reachability and parity feasibility are preserved.

## Improvement

1. I could have used distance function instead of those loops.

2. Checkout [DFS Solution](./better.cpp) written by the other person.
   - This works by checking feasibility on the directions on every move.
     (d -> l -> r -> u): are those feasible?
