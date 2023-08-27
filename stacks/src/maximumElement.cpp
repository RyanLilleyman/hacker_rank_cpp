#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

const vector<string> explode(const string &s, const char &c) {
  string buff{""};
  vector<string> v;
  for (auto n : s) {
    if (n != c)
      buff += n;
    else {
      if (n == c && buff != "") {
        v.push_back(buff);
        buff = "";
      }
    }
  }
  if (buff != "") {
    v.push_back(buff);
  }

  return v;
}

/*
 * Complete the 'getMax' function below
 *
 * the function is expected to return an integer array.
 * the function accepts string array operations as parameter.
 */
vector<int> getMax(vector<string> operations) {
  vector<int> stack;
  vector<int> maxStack;
  vector<int> answers;
  for (auto s : operations) {
    if (s[0] == '1') {
      vector<string> toPush = explode(s, ' ');
      stack.push_back(stoi(toPush[1]));
      if (maxStack.empty() ||
          stoi(toPush[1]) >= maxStack[maxStack.size() - 1]) {
        maxStack.push_back(stoi((toPush[1])));
      }
    } else if (s[0] == '2') {

      if (!stack.empty() &&
          stack[stack.size() - 1] == maxStack[maxStack.size() - 1]) {
        maxStack.pop_back();
      }
      stack.pop_back();
    } else {
      answers.push_back(maxStack[maxStack.size() - 1]);
    }
  }
  return answers;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string n_temp;
  getline(cin, n_temp);

  int n = stoi(ltrim(rtrim(n_temp)));
  vector<string> ops(n);

  for (int i = 0; i < n; i++) {
    string ops_item;
    getline(cin, ops_item);

    ops[i] = ops_item;
  }

  vector<int> res = getMax(ops);
  for (size_t i = 0; i < res.size(); i++) {
    fout << res[i];

    if (i != res.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";
  fout.close();
  return 0;
}

string ltrim(const string &str) {
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(),
                             [](unsigned char c) { return !isspace(c); }));

  return s;
}

string rtrim(const string &str) {
  string s(str);
  s.erase(
      find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !isspace(c); })
          .base(),
      s.end());

  return s;
}
