#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'compareTriplets' function below.
 * the function is expected to return an integer array.
 * the function accepts the following parameters
 * 1.integer array a
 * 2.integer array b
 */
vector<int> compareTriplets(vector<int> a, vector<int> b) {
  vector<int> scores = {0, 0};
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == b[i]) {
      continue;
    } else if (a[i] > b[i]) {
      scores[0] += 1;
    } else if (a[i] < b[i]) {
      scores[1] += 1;
    }
  }
  return scores;
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string aTempTemp;
  getline(cin, aTempTemp);

  vector<string> aTemp = split(rtrim(aTempTemp));
  vector<int> a(3);

  for (int i = 0; i < 3; i++) {
    int aItem = stoi(aTemp[i]);
    a[i] = aItem;
  }

  string bTempTemp;
  getline(cin, bTempTemp);

  vector<string> bTemp = split(rtrim(bTempTemp));

  vector<int> b(3);
  for (int i = 0; i < 3; i++) {
    int bItem = stoi(bTemp[i]);
    b[i] = bItem;
  }

  vector<int> result = compareTriplets(a, b);
  for (size_t i = 0; i < result.size(); i++) {
    fout << result[i];
    if (i != result.size() - 1) {
      fout << " ";
    }
  }

  fout << "\n";
  fout.close();

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
