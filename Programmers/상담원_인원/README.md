# 상담원 인원

Solved at: 2026-01-17 (40m)

https://school.programmers.co.kr/learn/courses/30/lessons/214288

Bruteforce

## Overview

Only number of consultants matter, so generate all the possible pairs and
calculate their minimum.

## Generating the pairs

This problem is equivalent to $a _ 1 + a _ 2 + \cdots = k, a _ i \ge 1$.

The solution to this is known as $_ {k - n} H _ n$.

Since $_ {15} H _ 5 \le 16000$, All the pairs can be made through bruteforce.

## Calculating the Time taken for each pair

For each type of consultation, make a time managing slot.

For each slots, find the slot with miniumn time $t$.

- if $t \le req$,

  This means that the consultant is available.

  The participant does not have to wait.

  The consultant's time is moved to end of the session.

- otherwise,

  The consultant is unavailable.

  The participant has to wait until the consultant is available.

  Add this to the cost.
