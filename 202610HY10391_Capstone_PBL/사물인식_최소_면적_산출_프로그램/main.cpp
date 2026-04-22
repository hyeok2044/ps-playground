#include <bits/stdc++.h>
#include <sys/types.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

typedef struct {
  int r;
  int c;
  int k;
} point;

int           n, k;
vector<point> colors[21];
point         pts[100];
int           ans = 123456789;

inline int area(int lr, int lc, int rr, int rc)
{
  return (rr - lr) * (rc - lc);
}

void dfs(int depth, int lr, int lc, int rr, int rc)
{
  if (depth == k + 1) {
    ans = area(lr, lc, rr, rc);
    return;
  }
  for (point p : colors[depth]) {
    int nlr = min(lr, p.r);
    int nlc = min(lc, p.c);
    int nrr = max(rr, p.r);
    int nrc = max(rc, p.c);
    int a   = area(nlr, nlc, nrr, nrc);
    if (a >= ans) {
      continue;
    }
    dfs(depth + 1, nlr, nlc, nrr, nrc);
  }
}

int main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    point p;
    cin >> p.r >> p.c >> p.k;
    pts[i] = p;
    colors[p.k].push_back(p);
  }

  for (point p : colors[1]) {
    dfs(2, p.r, p.c, p.r, p.c);
  }
  cout << ans << endl;
}
