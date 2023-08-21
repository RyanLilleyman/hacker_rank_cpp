#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  string a, b, c;
  cin >> a >> b;
  c = a + b;
  cout << a.length() << " " << b.length() << '\n' << c << '\n';
  char a0 = a[0];
  char b0 = b[0];
  b[0] = a0;
  a[0] = b0;
  cout << a << " " << b;
  return 0;
}
