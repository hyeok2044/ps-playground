typedef long long ll;

ll memo[100001];
ll sum[3];

// 2026-01-11 12:30 ~ 13:00
int solution(int n)
{
  int answer = 0;
  memo[0]    = 1;
  memo[1]    = 1;
  memo[2]    = 3;
  memo[3]    = 10;
  sum[0]     = 1;
  for (int i = 4; i <= n; i++) {
    memo[i] = memo[i - 1] * 1 + memo[i - 2] * 2 + memo[i - 3] * 5;
    memo[i] += sum[(i + 2) % 3] * 2 + sum[(i + 1) % 3] * 2 + sum[i % 3] * 4;
    memo[i] %= (ll)1'000'000'007;

    sum[(i - 3) % 3] += memo[i - 3];
    sum[(i - 3) % 3] %= (ll)1'000'000'007;
  }

  return memo[n];
}
