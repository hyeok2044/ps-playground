# 억억단을 외우자

Solved at: 2026-01-12 (40m)

https://school.programmers.co.kr/learn/courses/30/lessons/138475

Time Complexity Analysis $O(n \log n)$

### Why is it O(nlogn)?

This code works in a way that:

```
  // 1 * 1, 1 * 2, ... , e - 1 * 1, e * 1
  for (int i = 1; i <= e; i++) {
    for (int j = i; j <= e; j += i) {
      divid[j]++;
    }
  }
```

This is not $O(n^2)$ since $j$ is incremented by $i$.

$$
\frac n1 + \frac n2 + \cdots + \frac nn = n \cdot \sum_{i = 1}^n  \frac1i
$$

This is a typical harmonic series that converges to $\log n$.

### Calculating with `starts`

since `e` is fixed, we can just start from `e` and go back all the way to `1`.
