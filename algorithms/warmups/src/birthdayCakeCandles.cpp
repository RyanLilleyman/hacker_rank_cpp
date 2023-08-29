#include <bits/stdc++.h>
#include <climits>
using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * the function is expected to return an integer.
 * the function accepts integer array candles as parameter.
 */
int birthdayCakeCandles(vector<int> candles) {
  int maximum = INT_MIN;
  int count = 0;
  for (int i = 0; i < candles.size(); i++) {
    if (maximum == candles[i]) {
      count += 1;
    }
    if (candles[i] > maximum) {
      count = 1;
      maximum = candles[i];
    }
  }
  return count;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string candlesCountTemp;
  getline(cin, candlesCountTemp);

  int candlesCount = stoi(ltrim(rtrim(candlesCountTemp)));

  string candlesTempTemp;
  getline(cin, candlesTempTemp);

  vector<string> candlesTemp = split(rtrim(candlesTempTemp));
  vector<int> candles(candlesCount);

  for (int i = 0; i < candlesCount; i++) {
    int candlesItem = stoi(candlesTemp[i]);
    candles[i] = candlesItem;
  }

  int result = birthdayCakeCandles(candles);
  fout << result << "\n";
  fout.close();

  return 0;
}

string rtrim(const string &str) {
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(),
                             [](unsigned char c) { return !isspace(c); }));

  return s;
}

string ltrim(const string &str) {
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
