# 숫자 타자 대회

Solved at: 2026-01-17 (30m)

https://school.programmers.co.kr/learn/courses/30/lessons/136797

DP

## Distance between two numbers

This can be inferred with each positions of the numbers in numpad.

1. Same number: 1

2. Only difference in row/column: 2 \* `diff`

3. Others: 3 \* `min` + 2 \* `diff`

This can actually be converted to

```
int getDist(int a, int b)
{

  if (a == b)    // insta click
    return 1;
  int dr = abs(numpad[a].first - numpad[b].first);
  int dc = abs(numpad[a].second - numpad[b].second);
  if (dr < dc)
    swap(dr, dc); // dr >= dc
  int diff = dr - dc;
  return dc * 3 + diff * 2;
}
```

This is different from the actual, code, but shorter.

Hard coding, DFS are some other ways to deal with this.

## Setting DP

We only need the previous left hand, right hand position to determine
the optimal distance.

$dp[number][left][right]$: optimal distance when position of left hand,
right hand is `left`, `right` and the number is currently `number`.

$$
dp(number, num, right) = \max (dp(number - 1, k, right) + dist(k, num)), k \in[0, 9]
$$

vice versa for the right.

Remember to skip the calculation for $left = right$.
