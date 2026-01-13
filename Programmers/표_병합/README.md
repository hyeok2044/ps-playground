# 표 병합

Solved at: 2026-01-14 (50m)

https://school.programmers.co.kr/learn/courses/30/lessons/150366

DSU

## DSU

[Disjoint Set Union/Union-Find](https://cp-algorithms.com/data_structures/disjoint_set_union.html) will have an operation to combine any two sets,

and it will be able to tell in which set a specific element is.

### Initialization

```
  for (int i = 0; i < 10000; i++) {
    parents[i] = i;
  }
```

by default, it is considered the "main" node if `parents[i] = i`.

### find

```
int find(int a) {
  if (a == parents[a]) return a;
  return parents[a] = find(parents[a]);  // path compression
}
```

basic path compression.

### merge

```
void merge(int a, int b)
{
  int pa = find(a);
  int pb = find(b);
  if (pa == pb)
    return;
  parents[pb] = pa;
}
```

## Command parsing

`stringstream` can be used instead of manual parsing to avoid human errors.

```
#include <sstream>
stringstream ss;

ss << "10 20";
int x, y;
ss >> x >> y;
```

It is not implemented in this code, but it can be left for a simpler
implementation next time.

## Command Implementation

### UPDATE

1. Convert all of the strings in `vec`

2. Find the root node using `find(x)`, and change the string there.

### MERGE

1. Back up the string first.

2. Merge the cells

3. Restore the string.

### UNMERGE

1. Back up the string first.

2. **Iterate through all nodes to ensure the path compression.**

3. If the node shares the same parent, unmerge them and set its parent as
   itself.

   ```
     // 2
     for (int i = 0; i < 10000; i++) {
       find(i);
     }

     // 3
     for (int i = 0; i < 10000; i++) {
       if (find(i) == par1) {
         vec[i]     = "EMPTY";
         parents[i] = i;
       }
     }
   ```

4. Restore the string.

### PRINT

Initial values of the strings can be set as `EMPTY` since the input is
guaranteed to only have lowercase alphabets or numbers.

## Possible Improvements

1. `vec[x]` is meaningful only when `x` is a root. Non-root values are ignored (kept EMPTY).

2. Since indexing only depends on the `getIndex` function, we could have set the
   limit to 2.5K instead of current 10K.
