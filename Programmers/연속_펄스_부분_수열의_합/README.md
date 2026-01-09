# 봉인된 주문

Solved at: 2026-01-09 (20m)

https://school.programmers.co.kr/learn/courses/30/lessons/161988

DP - Maximum Subarray Sum

### Kadane's Algorithm

Normal form

$$ dp[i] = a[i] + \max(dp[i-1], 0) $$

We don't actually need array for this.

```
// Code from: https://www.geeksforgeeks.org/dsa/largest-sum-contiguous-subarray/
int maxSubarraySum(vector<int> &arr) {

    // Stores the result (maximum sum found so far)
    int res = arr[0];

    // Maximum sum of subarray ending at current position
    int maxEnding = arr[0];

    for (int i = 1; i < arr.size(); i++) {

        // Either extend the previous subarray or start
        // new from current element
        maxEnding = max(arr[i], maxEnding + arr[i]);

        // Update result if the new subarray sum is larger
        res = max(res, maxEnding);
    }
    return res;
}
```

### Pulsing

Instead of thinking it individually, the only possible formation can be in the
form of:

```
+ - + - + - + - ...
- + - + - + - + ...
```

This is equivalent to applying pulse to the entire sequence,
and getting its maximum subarray sum or -(minimum subarray sum).

```
memo[i]    = sequence[i - 1] + max(memo[i - 1], 0ll);
negMemo[i] = sequence[i - 1] + min(negMemo[i - 1], 0ll);

long long answer = 0;
for (int i = 0; i <= n; i++) {
    answer = max(memo[i], answer);
    answer = max(-negMemo[i], answer);
}
return answer;
```
