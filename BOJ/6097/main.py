a, b = map(int, input().split())
c = str(a ** b)
i = 0;
for ch in c:
    i = i + 1;
    print(ch, end='')
    if i % 70 == 0:
        print()
