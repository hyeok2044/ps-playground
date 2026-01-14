#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

#define endl '\n'

// 2026-01-14 09:15 ~ 09:25
// 6367 Color Me Less

class color
{
public:
  int r;
  int g;
  int b;
  color(int r, int g, int b) : r(r), g(g), b(b){};
  void print()
  {
    cout << "(" << r << "," << g << "," << b << ")";
  }
};

int dist(color c1, color c2)
{
  int dr = c1.r - c2.r;
  int dg = c1.g - c2.g;
  int db = c1.b - c2.b;
  return dr * dr + dg * dg + db * db;
}

vector<color> maps;
int           main(void)
{
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < 16; i++) {
    int r, g, b;
    cin >> r >> g >> b;
    maps.emplace_back(r, g, b);
  }

  int a, b, c;
  cin >> a >> b >> c;
  while (!(a == -1 && b == -1 && c == -1)) {
    color cur = color(a, b, c);
    int   mnm = dist(maps[0], cur);
    int   idx = 0;
    for (int i = 1; i < 16; i++) {
      int d = dist(maps[i], cur);
      if (d < mnm) {
        idx = i;
        mnm = d;
      }
    }
    cur.print();
    cout << " maps to ";
    maps[idx].print();
    cout << endl;

    cin >> a >> b >> c;
  }
}
