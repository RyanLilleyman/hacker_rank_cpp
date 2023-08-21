#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

const vector<string> explode(const string &s, const char &c) {
  vector<string> v;
  string buff{""};
  for (auto n : s) {
    if (n != c) {
      buff += n;
    } else if (n == c && buff != "") {
      v.push_back(buff);
      buff = "";
    }
  }
  if (buff != "") {
    v.push_back(buff);
  }
  return v;
}

const vector<int> convert_to_integer(const vector<string> &filtered) {
  vector<int> converted;
  for (auto s : filtered) {
    converted.push_back(stoi(s));
  }
  return converted;
}

const vector<int> parse_integers(stringstream &str) {
  string s = str.str();
  vector<int> to_return = convert_to_integer(explode(s, ','));
  return to_return;
}

int main() {
  std::string s;
  std::cin >> s;
  std::stringstream ss(s);
  vector<int> ahoy = parse_integers(ss);
  for (int a : ahoy) {
    printf("%d ", a);
  }
  return 0;
}
