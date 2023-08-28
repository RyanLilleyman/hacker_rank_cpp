#include <bits/stdc++.h>
#include <functional>
#include <pthread.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * the function accepts integer array arr as parameter.
 */

void plusMinus(vector<int> arr) {
  float lessThanZero = 0;
  float zero = 0;
  float greaterThanZero = 0;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] == 0) {
      zero += 1;
    } else if (arr[i] < 0) {
      lessThanZero += 1;
    } else if (arr[i] > 0) {
      greaterThanZero += 1;
    }
  }

  zero = zero / arr.size();
  lessThanZero = lessThanZero / arr.size();
  greaterThanZero = greaterThanZero / arr.size();
  if (zero < 0) {
    zero = -zero;
  }
  if (lessThanZero < 0) {
    lessThanZero = -lessThanZero;
  }
  if (greaterThanZero < 0) {
    greaterThanZero = -greaterThanZero;
  }
  cout << greaterThanZero << "\n";
  cout << lessThanZero << "\n";
  cout << zero << "\n";
}

int main() {
  string nTemp;
  getline(cin, nTemp);

  int n = stoi(ltrim(rtrim(nTemp)));

  string arrTempTemp;
  getline(cin, arrTempTemp);

  vector<string> arrTemp = split(rtrim(arrTempTemp));

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    int arrItem = stoi(arrTemp[i]);
    arr[i] = arrItem;
  }

  plusMinus(arr);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  return s;
}

string rtrim(const string &str) {
  string s(str);

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
