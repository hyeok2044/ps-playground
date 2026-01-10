# 3495

https://www.acmicpc.net/problem/3495

Solved at: 2026-01-10 (5m)

### [Even–Odd Rule](https://en.wikipedia.org/wiki/Even%E2%80%93odd_rule)

Scanline algorithm was used to determine the insideness.

Area calculation was done like:

- If it is a border, add 1/2 to the area and modify the parity.

- If the oddity is singular, add 1 to the area.

- Calculate the parity each row.
