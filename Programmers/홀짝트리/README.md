# 홀짝트리

https://school.programmers.co.kr/learn/courses/30/lessons/388354

keypoint: true/rev ordered tree count is determined by its degree.

### example of true-ordered tree

```
odd / even / even / even    (node number)
3     1      1      1       (degree)
O   / X    / X    / X       (parity)
```

only one has different parity.

### example of reverse-ordered tree

```
even / odd / odd / odd
3      1     1     1
X    / O   / O   / O
```

only one has same parity.

### edge case

single node tree is true-ordered when it is even, and vice versa.
