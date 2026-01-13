#include <string>
#include <vector>

using namespace std;

int getIndex(int r, int c)
{
  return r * 100 + c;
}

int            parents[10000];
vector<string> vec(10000, "EMPTY");
// 2026-01-13 16:50 (failed)
// 2026-01-14 05:20 ~ 05:40
// DSU, not necessarilly excel-like.

int find(int a)
{
  if (a == parents[a])
    return a;
  return parents[a] = find(parents[a]);
}

void merge(int a, int b)
{
  int pa = find(a);
  int pb = find(b);
  if (pa == pb)
    return;
  parents[pb] = pa;
}

vector<string> solution(vector<string> commands)
{
  vector<string> answer;
  for (int i = 0; i < 10000; i++) {
    parents[i] = i;
  }

  for (string command : commands) {
    vector<string> tokens;
    string         cur = "";
    for (char c : command) {
      if (c == ' ') {
        tokens.emplace_back(cur);
        cur = "";
      } else {
        cur += c;
      }
    }
    tokens.emplace_back(cur);

    if (tokens[0] == "UPDATE") {
      if (tokens.size() == 3) {
        for (int i = 0; i < 10000; i++) {
          if (vec[i] == tokens[1]) {
            vec[i] = tokens[2];
          }
        }
      } else {
        int idx     = getIndex(stoi(tokens[1]), stoi(tokens[2]));
        int parIdx  = find(idx);
        vec[parIdx] = tokens[3];
      }
    } else if (tokens[0] == "MERGE") {
      int    idx1 = getIndex(stoi(tokens[1]), stoi(tokens[2]));
      int    idx2 = getIndex(stoi(tokens[3]), stoi(tokens[4]));
      string str1 = vec[find(idx1)];
      string str2 = vec[find(idx2)];
      if (str1 != "EMPTY") {
        str2 = str1;
      }
      merge(idx1, idx2);
      int idx        = getIndex(stoi(tokens[1]), stoi(tokens[2]));
      vec[find(idx)] = str2;
    } else if (tokens[0] == "UNMERGE") {
      int    idx1 = getIndex(stoi(tokens[1]), stoi(tokens[2]));
      int    par1 = find(idx1);
      string str1 = vec[par1];

      for (int i = 0; i < 10000; i++) {
        find(i);
      }

      for (int i = 0; i < 10000; i++) {
        if (find(i) == par1) {
          vec[i]     = "EMPTY";
          parents[i] = i;
        }
      }
      vec[idx1] = str1;
    } else if (tokens[0] == "PRINT") {
      int idx1 = getIndex(stoi(tokens[1]), stoi(tokens[2]));
      int par1 = find(idx1);
      answer.emplace_back(vec[par1]);
    }
  }
  return answer;
}
