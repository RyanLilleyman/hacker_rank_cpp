#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <sstream>
#include <vector>

using namespace std;

void printHex(double a_d) {
  int64_t a = trunc(a_d);
  cout << "0x" << std::hex << a << "\n" << std::dec;
}

void printWithUnderscores(double b_d) {
  int absVal = static_cast<int>(abs(b_d));
  int digitsCount = (absVal == 0) ? 0 : 1;

  while (absVal) {
    absVal /= 10;
    digitsCount++;
  }

  int underscoresCount = 15 - digitsCount - 3;
  for (int i = 0; i < underscoresCount; i++) {
    cout << "_";
  }

  cout << (b_d >= 0 ? "+" : "-");
  cout << fixed << setprecision(2) << abs(b_d) << "\n";
}

void printScientific(double c) {
  ostringstream oss;
  oss << scientific << setprecision(9) << c;
  string formatted = oss.str();
  replace(formatted.begin(), formatted.end(), 'e', 'E');
  cout << formatted << "\n";
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    double a_d, b_d, c;
    cin >> a_d >> b_d >> c;

    printHex(a_d);
    printWithUnderscores(b_d);
    printScientific(c);
  }

  return 0;
}
