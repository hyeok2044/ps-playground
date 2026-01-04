#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// returns -1 if base check is failed.
int baseToInt(string s, int base)
{
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    ans *= base;
    int temp = s[i] - '0';
    if (temp >= base)
      return -1;
    ans += temp;
  }
  return ans;
}

// returns empty string if base check is failed.
string intToBase(int n, int base)
{
  if (n == 0)
    return "0";
  if (n < 0) {
    return "";
  }
  string s = "";
  while (n > 0) {
    s += (char)((n % base) + '0');
    n /= base;
  }
  reverse(s.begin(), s.end());
  return s;
}

vector<vector<string>> parseExpr(vector<string> &expressions)
{
  vector<vector<string>> parsed;
  for (string expr : expressions) {
    vector<string> exp;
    int            idx = 0;
    string         a   = "";
    while (expr[idx] != ' ') {
      a += expr[idx++];
    }
    exp.push_back(a);
    idx++;

    string operand = "";
    operand += expr[idx++];
    idx++;
    exp.push_back(operand);

    string b = "";
    while (expr[idx] != ' ') {
      b += expr[idx++];
    }
    exp.push_back(b);
    idx++;

    idx++; // equals
    idx++;

    string c = "";
    while (idx < expr.length()) {
      c += expr[idx++];
    }
    exp.push_back(c);

    parsed.push_back(exp);
  }
  return parsed;
}

vector<string> solution(vector<string> expressions)
{
  // a, op, b, c
  vector<vector<string>> parsed = parseExpr(expressions);

  bool availableBases[10];
  for (int i = 2; i <= 9; i++) {
    availableBases[i] = true;
  }

  // Parse Check Phase
  for (int base = 2; base <= 9; base++) {
    for (auto expr : parsed) {
      if (expr[3] == "X") {
        int  a    = baseToInt(expr[0], base);
        bool plus = expr[1] == "+";
        int  b    = baseToInt(expr[2], base);
        if (a == -1 || b == -1) {
          availableBases[base] = false;
        }
        continue;
      }
      int  a    = baseToInt(expr[0], base);
      bool plus = expr[1] == "+";
      int  b    = baseToInt(expr[2], base);
      int  c    = baseToInt(expr[3], base);
      if (a == -1 || b == -1 || c == -1) {
        availableBases[base] = false;
        continue;
      }
      if (plus) {
        if (a + b != c)
          availableBases[base] = false;
      } else {
        if (a - b != c)
          availableBases[base] = false;
      }
    }
  }

  // Calculation check phase
  for (int base = 2; base <= 9; base++) {
    if (!availableBases[base])
      continue;

    for (int i = 0; i < parsed.size(); i++) {
      vector<string> expr = parsed[i];
      if (expr[3] != "X")
        continue;
      int  a    = baseToInt(expr[0], base);
      bool plus = expr[1] == "+";
      int  b    = baseToInt(expr[2], base);

      string c = "";
      if (plus) {
        c = intToBase(a + b, base);
      } else {
        c = intToBase(a - b, base);
      }

      bool chk = true;
      for (int i = 4; i < expr.size(); i++) {
        if (expr[i] == c) {
          chk = false;
          break;
        }
      }

      if (chk) {
        parsed[i].push_back(c);
      }
    }
  }

  // Answer building phase
  vector<string> answer;
  for (auto expr : parsed) {
    string s;
    if (expr[3] == "X") {
      if (expr.size() == 5) {
        s = expr[0] + " " + expr[1] + " " + expr[2] + " = " + expr[4];
      } else {
        s = expr[0] + " " + expr[1] + " " + expr[2] + " = ?";
      }
    } else
      continue;
    answer.push_back(s);
  }
  return answer;
}
