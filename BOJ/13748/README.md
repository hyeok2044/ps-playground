# 13748

## Periodic Strings

https://www.acmicpc.net/problem/13748

Solved at: 2026-01-10 (15m)

String

naive implementation:

```
for i in n to 1 descending
    then
    if n is divisible by i
        then split the strings by i.
        for s in split strings
            then
            Rotate_Right(val)
            compare each elements to the generated string.
            end for
        if all s is satisfying
            then update answer.
            end then
        end then
    end for

function Rotate_Right(x):
    return x[last] + x[0 .. last-1]
```
