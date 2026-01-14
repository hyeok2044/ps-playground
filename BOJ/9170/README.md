# 9170

https://www.acmicpc.net/problem/9170

eval function

## two methods for reading until `EOF` in python

### `sys.stdin`

```
import sys

for line in sys.stdin:
    line = line.rstrip('\n')
    if line == "":
        continue
    print(line)
```

### Exception

```
while True:
    try:
        s = input()
        print(eval(s))
    except EOFError:
        break
```
