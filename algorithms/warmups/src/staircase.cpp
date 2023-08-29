#include <bits/stdc++.h>
using namespace std;

string rtrim(const string &);
string ltrim(const string &);

/*
 * Complete the 'staircase' function below.
 *
 * the function accepts integer n as a parameter
 */
void staircase(int n) {
  for (int i = 0; i < n; i++) {
    int j = (n - 1 - i);
    int tempj = j;

    while (j) {
      cout << ' ';
      j -= 1;
    }
    int k = (n - tempj);

    while (k) {
      cout << '#';
      k -= 1;
    }
    cout << "\n";
  }
}

int main() {
  string nTemp;
  getline(cin, nTemp);

  int n = stoi(ltrim(rtrim(nTemp)));
  staircase(n);

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
