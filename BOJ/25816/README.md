# 25816

https://www.acmicpc.net/problem/25816

Solved at: 2026-01-14 (15m)

Sorting

### `unordered_map`

Instead of using `um[str] == 0` for non-existent,

It is better to use

```
if (um.find(str) == um.end()) {
    ...
```

instead.

### Sorting

This problem requires data structure and custom sorting.

Although it might not have been a problem to use float or double,

It is better in practice to use multiplication instead.

```
bool comp(univ a, univ b)
{
  return a.rankSum * b.num < b.rankSum * a.num;
}
```

### ignore

when `cin` and `getline` is used at the same time, cin may not finish with `\n`,
making one line empty.

We can use `cin.ignore()` to prevent those issues.

## Improvement

1. In my code, `int` datatype is used, but using `long long` datatype might be
   better.

2. Although the problem mentioned the unique ordering, it is nicer to have
   strict sorting in `comp` function.
