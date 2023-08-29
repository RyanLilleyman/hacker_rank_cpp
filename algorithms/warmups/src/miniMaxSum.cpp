#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * the function accepts integer array as parameter.
 */

void miniMaxSum(vector<int> arr) {
  sort(arr.begin(), arr.end());
  long miniSum = 0;
  long maxSum = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (i < arr.size() - 1) {
      miniSum += arr[i];
    }
    if (i > 0) {
      maxSum += arr[i];
    }
  }
  cout << miniSum << " " << maxSum;
}

int main() {

  string arrTempTemp;
  getline(cin, arrTempTemp);

  vector<string> arrTemp = split(rtrim(arrTempTemp));

  vector<int> arr(5);

  for (int i = 0; i < 5; i++) {
    int arrItem = stoi(arrTemp[i]);
    arr[i] = arrItem;
  }

  miniMaxSum(arr);
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
