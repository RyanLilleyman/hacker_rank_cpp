#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  int e;
  cin >> e;
  v.erase(v.begin() + (e - 1));

  int q1, q2;
  cin >> q1 >> q2;

  v.erase(v.begin() + (q1 - 1), v.begin() + (q2 - 1));

  int size2;
  size2 = v.size();
  cout << size2 << "\n";

  // prints vector
  for (int i = 0; i < size2; i++) {
    cout << v[i] << " ";
  }
  return 0;
}
