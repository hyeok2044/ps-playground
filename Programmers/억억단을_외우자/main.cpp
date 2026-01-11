#include <vector>

using namespace std;

// 2026-01-12 05:55 ~ 06:31

int divid[5000001];
int ans[5000001];

vector<int> solution(int e, vector<int> starts)
{
  for (int i = 1; i <= e; i++) {
    for (int j = i; j <= e; j += i) {
      divid[j]++;
    }
  }
  int cur = 0;
  int mxm = 0;
  for (int i = e; i >= 1; i--) {
    if (divid[i] >= mxm) {
      cur = i;
      mxm = divid[i];
    }
    ans[i] = cur;
  }
  vector<int> answer;
  for (auto i : starts) {
    answer.push_back(ans[i]);
  }
  return answer;
}
