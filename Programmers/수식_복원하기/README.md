# 수식 복원하기

Solved at: 2026-01-05 (1h)

https://school.programmers.co.kr/learn/courses/30/lessons/340210

### Parsing

Since the input is fixed as ` A + B = C / A - B = C`, naive parsing was used.
(`parseExpr`)

### Error handling

1. Number to String conversion is not possible if base is not enough.

`Error values` are used to support those.

```
// returns empty string if base check is failed.
string intToBase(int n, int base)
...

// returns -1 if base check is failed.
int baseToInt(string s, int base)
```

2. Pruning is always attmpted.

during the parse check phase, feasibility of the `base` is marked.

ex) `5` cannot be input on base `4`.

```
int  a    = baseToInt(expr[0], base);
bool plus = expr[1] == "+";
int  b    = baseToInt(expr[2], base);
int  c    = baseToInt(expr[3], base);
if (a == -1 || b == -1 || c == -1) {
  availableBases[base] = false;
  continue;
}
```

### Checking for X values

This seems better to implement with `set`, or `unordered map`.

Basic linear search is used in this code to prevent mixing up the answer.

```

for (int i = 0; i < parsed.size(); i++) {
 ...

  bool chk = true;
  for (int i = 4; i < expr.size(); i++) {
    if (expr[i] == c) {
      chk = false;
      break;
    }
  }

  if (chk) {
    parsed[i].push_back(c);
  }
}
```

Last line, `parsed[i]` can be prevented by using `for(const auto& expr : parsed)` instead.

This gives out reference instead of copying the whole vector.
