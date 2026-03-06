#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <execution>
#endif

#include <iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

#define CMD_INIT (100)
#define CMD_ENTER (200)
#define CMD_PULL_OUT (300)
#define CMD_SEARCH (400)

// START OF USER CODE

using namespace std;
class car
{
public:
  int    inTime;
  string park;
  car(int a, string b) : inTime(a), park(b){};
  car() : inTime(-1), park(""){};
};

class parking_car
{
public:
  int    inTime;
  int    idx;
  int    num;
  string carName;
  parking_car(int a, int b, int c, string d)
      : inTime(a), idx(b), num(c), carName(d){};
};

int n, m, l;

priority_queue<int, vector<int>, greater<int>> parking_slot[26];

queue<parking_car>         leaveQueue;
unordered_map<string, int> car_list;

car realSlot[26][1000];

char locname[5];

struct RESULT_E {
  int  success;
  char locname[5];
};

struct RESULT_S {
  int  cnt;
  char carlist[5][8];
};

void encodeLocation(int idx, int num)
{

  locname[0] = idx + 'A';
  locname[1] = (num / 100) + '0';
  num -= (num / 100) * 100;
  locname[2] = (num / 10) + '0';
  num -= (num / 10) * 10;
  locname[3] = num + '0';
  locname[4] = '\0';
}

void init(int N, int M, int L)
{
  n = N;
  m = M;
  l = L;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      parking_slot[i].emplace(j);
    }
  }

  return;
}

RESULT_E enter(int mTime, char mCarNo[])
{
  RESULT_E res_e;
  while (!leaveQueue.empty()) {
    parking_car p = leaveQueue.front();
    if (p.inTime + l <= mTime) {
      cout << p.idx << " " << p.num << " pushed" << endl;
      parking_slot[p.idx].push(p.num);
      car_list.erase(p.carName);
      realSlot[p.idx][p.num].inTime = -1;
      realSlot[p.idx][p.num].park   = "";
      leaveQueue.pop();
      continue;
    }
    break;
  }
  int mxm = 0;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    cout << parking_slot[i].size() << " ";
    if (parking_slot[i].size() > mxm) {
      idx = i;
      mxm = parking_slot[i].size();
    }
  }
  cout << endl;

  if (mxm == 0) {
    res_e.success = 0;
    return res_e;
  }

  res_e.success = 1;
  int num       = parking_slot[idx].top();
  parking_slot[idx].pop();
  encodeLocation(idx, num);
  for (int i = 0; i < 5; i++) {
    res_e.locname[i] = locname[i];
  }
  string s           = string(mCarNo);
  car_list[s]        = (idx + 1) * m + num;
  realSlot[idx][num] = car(mTime, s);
  leaveQueue.emplace(mTime, idx, num, s);
  cout << idx << " " << num << " entered" << endl;

  return res_e;
}

int pullout(int mTime, char mCarNo[])
{
  string s   = string(mCarNo);
  int    ret = car_list[s];
  if (ret == 0) {
    return -1;
  }
  int idx = ret / m - 1;
  int num = ret % m;
  car c   = realSlot[idx][num];
  if (c.park != s) {
    return -1;
  }
  int diff                  = mTime - c.inTime;
  realSlot[idx][num].park   = "";
  realSlot[idx][num].inTime = -1;
  parking_slot[idx].push(num);
  cout << idx << " " << num << " pushed" << endl;
  if (diff > l) {
    return -(diff + (diff - l) * 5);
  }
  return diff;
}

RESULT_S search(int mTime, char mStr[])
{
  RESULT_S res_s;

  string s = "AAA";
  for (int i = 0; i < 4; i++) {
    s += mStr[i];
  }
  vector<string> pullover;
  vector<string> non_pullover;
  for (int i = 0; i < 10; i++) {
    s[0] = i + '0';
    for (int j = 0; j < 10; j++) {
      s[1] = j + '0';
      for (int k = 0; k < 26; k++) {
        s[2]    = j + 'A';
        int ret = car_list[s];
        if (ret == 0) {
          continue;
        }
        int idx = ret / m - 1;
        int num = ret % m;
        car c   = realSlot[idx][num];
        if (c.park != s) {
          continue;
        }
        int diff = mTime - c.inTime;
        if (diff > l) {
          pullover.push_back(s);
          continue;
        }
        non_pullover.push_back(s);
      }
    }
  }
  for (int i = 0; i < min((int)non_pullover.size(), 5); i++) {
    for (int j = 0; j < 7; j++) {
      res_s.carlist[i][j] = non_pullover[i][j];
    }
    res_s.carlist[i][7] = '\0';
  }

  for (int i = (int)non_pullover.size();
       i < min((int)(non_pullover.size() + pullover.size()), 5);
       i++) {
    for (int j = 0; j < 7; j++) {
      res_s.carlist[i][j] = pullover[i][j];
    }
    res_s.carlist[i][7] = '\0';
  }

  res_s.cnt = min((int)(non_pullover.size() + pullover.size()), 5);

  return res_s;
}

// END OF USER CODE

extern void     init(int N, int M, int L);
extern RESULT_E enter(int mTime, char mCarNo[]);
extern int      pullout(int mTime, char mCarNo[]);
extern RESULT_S search(int mTime, char mStr[]);

static bool run()
{
  int Q, N, M, L;
  int mTime;

  char mCarNo[8];
  char mStr[5];

  int ret = -1, ans;

  RESULT_E res_e;
  RESULT_S res_s;

  scanf("%d", &Q);

  bool okay = false;

  for (int q = 0; q < Q; ++q) {
    int cmd;
    scanf("%d", &cmd);
    switch (cmd) {
    case CMD_INIT:
      scanf("%d %d %d", &N, &M, &L);
      init(N, M, L);
      okay = true;
      break;
    case CMD_ENTER:
      scanf("%d %s", &mTime, mCarNo);
      res_e = enter(mTime, mCarNo);
      scanf("%d", &ans);
      cout << res_e.success << " " << ans << endl;
      if (res_e.success != ans)
        okay = false;
      if (ans == 1) {
        scanf("%s", mStr);
        if (strcmp(res_e.locname, mStr) != 0)
          okay = false;
      }
      break;
    case CMD_PULL_OUT:
      scanf("%d %s", &mTime, mCarNo);
      ret = pullout(mTime, mCarNo);
      scanf("%d", &ans);
      if (ret != ans)
        okay = false;
      break;
    case CMD_SEARCH:
      scanf("%d %s", &mTime, mStr);
      res_s = search(mTime, mStr);
      scanf("%d", &ans);
      if (res_s.cnt != ans)
        okay = false;
      for (int i = 0; i < ans; ++i) {
        scanf("%s", mCarNo);
        strcat(mCarNo, mStr);
        if (strcmp(res_s.carlist[i], mCarNo) != 0)
          okay = false;
      }
      break;
    default:
      okay = false;
      break;
    }
  }

  return okay;
}

int main()
{
  setbuf(stdout, NULL);
  // freopen("sample_input.txt", "r", stdin);

  int TC, MARK;

  scanf("%d %d", &TC, &MARK);
  for (int tc = 1; tc <= TC; ++tc) {
    int score = run() ? MARK : 0;
    printf("#%d %d\n", tc, score);
  }

  return 0;
}
