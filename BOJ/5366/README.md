# 5366

## Total Count

https://www.acmicpc.net/problem/5366

Solved at: 2026-01-10 (10m)

Map

## `map` / `unordered_map`

### Find

- `find()`

  ```
  if (mp.find(key) != mp.end()) {
      // key exists
  }
  ```

- `count()`

  ```
  if (mp.count(key)) {
      // key exists
  }
  ```

### Insertion

By default, values are initialized to zero.

- `operator[]`

  ```
  mp["apple"] = 3;
  mp["banana"]++; // 1
  ```

- `emplace()`

  ```
  mp.emplace("orange", 5);
  ```

> Emplace creates things within the container.
>
> It is ignored if key already exists.

### Erase

`erase(key / iterator)`

    ```
    mp.erase("apple");
    ```

### Iteration

- Range-based for loop

  ```
  for (auto &p : mp) {
      cout << p.first << " " << p.second << '\n';
  }
  ```

- Iterator

  ```
  for (auto it = mp.begin(); it != mp.end(); it++) {
      cout << it->first << " " << it->second << '\n';
  }
  ```

> Main difference: `map`: ordered here, `unordered_map` is not ordered.
>
> `map`: RB-Tree $O(\log n)$, `unordered_map`: Hashmap $O(1)$
