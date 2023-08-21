#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Student {
private:
  int sum;
  vector<int> grades;

public:
  void input_scores() {
    for (int i = 0; i < 5; i++) {
      int grade = 0;
      // printf("Enter the %d th score", i);
      scanf("%d", &grade);
      this->grades.push_back(grade);
    }
  }
  int grades_sum() {
    this->sum = 0;
    for (auto grade : this->grades) {
      sum += grade;
    }
    return this->sum;
  }
};

int main() {
  int size;
  int best_student = 0;
  scanf("%d", &size);
  Student Students[size];
  for (int i = 0; i < size; i++) {

    Students[i].input_scores();
    int result = Students[i].grades_sum();
    if (i != 0 && Students[0].grades_sum() < result) {
      best_student += 1;
    }
  }
  printf("%d", best_student);
  return 0;
}
