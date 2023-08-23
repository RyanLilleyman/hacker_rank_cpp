#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Box {
  int l, b, h;
  static Box *lastConstructed;

public:
  Box() : l(0), b(0), h(0) { lastConstructed = this; }
  Box(int breadth, int length, int height) : l(length), b(breadth), h(height) {
    if (lastConstructed) {
      lastConstructed->l = length;
      lastConstructed->b = breadth;
      lastConstructed->h = height;
    }
    lastConstructed = this;
  }
  int getLength() const { return l; }

  int getBreadth() const { return b; }

  int getheight() const { return h; }

  int CalculateVolume() const { return l * b * h; }

  // overloading the < operator
  bool operator<(const Box &other) {
    return this->CalculateVolume() < other.CalculateVolume();
  }

  friend ostream &operator<<(ostream &out, const Box &box) {
    out << box.l << " " << box.b << " " << box.h;
    return out;
  }
};

Box *Box::lastConstructed = nullptr;

int main() {
  int l, b, h;
  cin >> l >> b >> h;
  Box b1;
  Box b2(b, l, h);
  b2.getLength();
  b2.getBreadth();
  b2.getheight();
  b2.CalculateVolume();
  bool x = (b1 < b2);
  cout << b2;
  return 0;
}
