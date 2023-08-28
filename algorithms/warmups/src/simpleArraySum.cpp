#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

vector<string> split(const string &);

/*
 * Complete the 'simpleArraySum' function below.
 *
 * the function is expected to return an integer.
 * the function accepts integerArray as a parameter.
 */
int simpleArraySum(vector<int> ar) {
  int sum = 0;
  for (int i = 0; i < ar.size(); i++) {
    sum += ar[i];
  }
  return sum;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string arCountTemp;
  getline(cin, arCountTemp);

  int arCount = stoi(ltrim(rtrim(arCountTemp)));

  string arTempTemp;
  getline(cin, arTempTemp);

  vector<string> arTemp = split(rtrim(arTempTemp));
  vector<int> ar(arCount);

  for (int i = 0; i < arCount; i++) {
    int arItem = stoi(arTemp[i]);

    ar[i] = arItem;
  }

  int result = simpleArraySum(ar);

  fout << result << "\n";

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

vector<string> split(const string &str) {
  vector<string> tokens;
  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }
  tokens.push_back(str.substr(start));
  return tokens;
}
