#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);

  for (int &a : v) {
    cin >> a;
  }

  sort(v.begin(), v.end());
  int queries;
  cin >> queries;
  for (int i = 0; i < queries; i++) {
    int q;
    cin >> q;
    vector<int>::iterator low = lower_bound(v.begin(), v.end(), q);
    if (low != v.end() && *low == q) {
      cout << "Yes"
           << " " << distance(v.begin(), low) + 1 << "\n";
    } else {
      cout << "No"
           << " " << distance(v.begin(), low) + 1 << "\n";
    }
  }
  return 0;
}
