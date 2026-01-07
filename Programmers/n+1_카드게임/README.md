# n + 1 카드게임

Solved at: 2026-01-07 (failed)

https://school.programmers.co.kr/learn/courses/30/lessons/258707

Greedy

This can be easily managed by using sets.

1. Divide the cards into `hands` and `picks`

2. Goal is to maintain as much coins as possible.
   - Only from hands: 0 coin

   - hands + picks: 1 coin

   - Only from picks: 2 coins

### Useful operations:

```
// Initialization
set<T> s;

// Finding ptr
if(s.find(val) != s.end());

// Erasing the value
s.erase(val);

// Set iteration
for (auto it = s.begin(); it != s.end(); it++)
    *it = ...;
```
