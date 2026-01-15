# 에어컨

Solved at: 2026-01-15 (1h)

https://school.programmers.co.kr/learn/courses/30/lessons/214289

DP

### Key Points

1. **Time and temperatures** are the only two factors determining the energy
   consumption, so `dp` can be constructed like:

   `dp[i][j]`: Minimum energy consumption at time `i` and temperature `j`.

2. if `onboard[i] = 1`, `dp[i][j]` where `j < t1` or `j > t2` should not be calculated.

---

## Transition

Let `T` be the outside temperature (`temperature`).

At each minute, from state `(i, j)` we can move to `(i+1, j')` by choosing either
**AC OFF** or **AC ON**. Note that the desired temperature can be changed freely
while AC is ON, so we do not need to keep it as a state.

### 1) AC OFF (cost = 0)

When AC is off, the indoor temperature moves **toward the outside temperature** by 1 degree per minute.

- If `j < T` then `j' = j + 1`
- If `j > T` then `j' = j - 1`
- If `j == T` then `j' = j`

So:

- `dp[i+1][j'] = min(dp[i+1][j'], dp[i][j])`

### 2) AC ON

When AC is on, we can set the desired temperature such that:

- If we want to **change** the indoor temperature by 1 degree (`j -> j±1`),
  set desired temperature on that side.  
  Then `j' = j ± 1` and cost is `+a` (because indoor != desired during that minute).

- If we want to **maintain** the temperature (`j -> j`),
  set desired temperature to `j`.  
  Then `j' = j` and cost is `+b` (because indoor == desired during that minute).

So transitions are:

- `dp[i+1][j]   = min(dp[i+1][j],   dp[i][j] + b)`
- `dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + a)`
- `dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + a)`

(With boundary checks on the temperature range, e.g. `-10 ≤ j ≤ 40`.)

### Onboard constraint application

For every transition `(i, j) -> (i+1, j')`, if `onboard[i+1] == 1`, we must satisfy:

- `t1 ≤ j' ≤ t2`

Otherwise that transition is discarded.

---

## Improvements

- `tempToIndex` function is too long. Since only `t1, t2, t` variables are used,
  making another temporary variable is recommended.
- All of these cases are symmetric. I can make the code shorter by putting
  conditional statement inside the transition part.
- [Check the code written by the others](./better.cpp)
