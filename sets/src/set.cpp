#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int main() {
  set<int> s;
  int queries;
  cin >> queries;
  for (int i = 0; i < queries; i++) {
    int c, n;
    cin >> c >> n;
    if (c == 1) {
      s.insert(n);
    } else if (c == 2) {
      s.erase(n);
    } else if (c == 3) {
      set<int>::iterator itr = s.find(n);
      if (itr == s.end()) {
        cout << "No"
             << "\n";
      } else {
        cout << "Yes"
             << "\n";
      }
    }
  }
  return 0;
}
