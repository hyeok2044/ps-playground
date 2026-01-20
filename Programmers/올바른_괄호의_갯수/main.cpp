typedef long long int ll;

// 2026-01-21 05:55 ~ 06:55

ll cat[15];

int solution(int n)
{
  cat[0] = 1;
  cat[1] = 1;
  for (int i = 2; i <= 14; i++) {
    for (int j = 0; j < i; j++) {
      cat[i] += cat[j] * cat[i - 1 - j];
    }
  }
  return cat[n];
}
