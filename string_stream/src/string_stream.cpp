#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> parse_integers(stringstream &str) {
  char ch;
  int a, b, c;
  str >> a >> ch >> b >> ch >> c;
  vector<int> to_return = {a, b, c};
  return to_return;
}

int main() {
  stringstream ss("23,4,56");
  vector<int> ahoy = parse_integers(ss);
  for (int a : ahoy) {
    printf("%d ", a);
  }
  return 0;
}
