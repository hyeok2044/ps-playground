# 올바른 괄호의 갯수

Solved at: 2026-01-21 (1h)

https://school.programmers.co.kr/learn/courses/30/lessons/12929

Combinatorics

## Catallan's Number

$$
C _ 0 = 1, C _ {n + 1} = \sum _ {k = 0} ^ {n} C _ k \cdot C _ {n - k}
$$

Where does the first `(` close?

The form can always be formed in such way:

```
( 2k ) 2 * {n - 1 - k}
```

Therefore, we can iterate through all `k`'s to get the same result.

---

This can be also be formed like

$C _ n = \frac{1}{n + 1} _ {2n} C _ {n}$
