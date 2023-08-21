#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct MyStruct {
  int age;
  char first_name[51];
  char last_name[51];
  int standard;
};

void printStructWithLabel(const MyStruct &student) {
  cout << "Age: " << student.age << '\n';
  cout << "First: " << student.first_name << '\n';
  cout << "Last: " << student.last_name << '\n';
  cout << "Standard: " << student.standard << '\n';
}

void printStruct(const MyStruct &student) {
  cout << student.age << " ";
  cout << student.first_name << " ";
  cout << student.last_name << " ";
  cout << student.standard << " ";
}

int main() {
  MyStruct student;

  scanf("%d %50s %50s %d", &student.age, student.first_name, student.last_name,
        &student.standard);
  printStruct(student);

  return 0;
}
