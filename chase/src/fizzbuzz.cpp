#include <bits/stdc++.h>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'fizzBuzz' function below.
 * the function accepts integer n as parameter.
 */

void fizzBuzz(int n) {
  for (int i = 0; i <= n; i++) {
    if (i % 5 == 0 && i % 3 == 0) {
      cout << "FizzBuzz"
           << "\n";
    } else if (i % 5 == 0) {
      cout << "Buzz"
           << "\n";
    } else if (i % 3 == 0) {
      cout << "Fizz"
           << "\n";
    } else {
      cout << i << "\n";
    }
  }
}
int main() {
  string nTemp;
  getline(cin, nTemp);

  int n = stoi(ltrim(rtrim(nTemp)));

  fizzBuzz(n);

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
