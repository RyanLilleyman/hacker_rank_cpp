#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;

int main() {
  map<string, int> students;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int c;
    string name;
    cin >> c >> name;
    if (c == 1) {
      int score;
      cin >> score;
      map<string, int>::iterator check = students.find(name);
      if (check == students.end()) {
        students.insert(make_pair(name, score));
      } else {
        int current_score = check->second;
        int result;
        result = current_score + score;
        students.erase(name);
        students.insert(make_pair(name, result));
      }
    } else if (c == 2) {
      students.erase(name);
    } else if (c == 3) {
      map<string, int>::iterator itr = students.find(name);
      if (itr == students.end()) {
        cout << 0 << "\n";
      } else {
        cout << itr->second << "\n";
      }
    }
  }
  return 0;
}
