# 12007

https://www.acmicpc.net/problem/12007

Solved at: 2026-01-14 (30m)

Bruteforce

```
  int answer = 0x7fffffff;
  for (int i = 0; i < n; i++) {
    int minx = x[0], miny = y[0];
    int maxx = x[x.size() - 1], maxy = y[y.size() - 1];
    if (cow[i].first == minx)
      minx = x[1];
    if (cow[i].first == maxx)
      maxx = x[x.size() - 2];
    if (cow[i].second == miny)
      miny = y[1];
    if (cow[i].second == maxy)
      maxy = y[y.size() - 2];
    answer = min(answer, (maxx - minx) * (maxy - miny));
  }
```

For all the cows, we can calcuate the minimum and maximum without it.

$n \le 50000$, so optimization is required

We also know that only one will be moved out, so we can calcuate this like

the code above.
