#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class Student {
private:
  int age;
  std::string first_name;
  std::string last_name;
  int standard;

public:
  int set_age(int age = 0, bool is_provided = false) {
    if (!is_provided) {
      printf("Enter the age: ");
      scanf("%d", &age);
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return this->age = age;
    } else {
      return this->age = age;
    }
  }
  string set_first_name(string first = "FirstNameHere",
                        bool is_provided = false) {
    if (!is_provided) {
      printf("Enter the first name: ");
      std::getline(cin, first);
      return this->first_name = first;
    } else {
      return this->first_name = first;
    }
  }
  string set_last_name(string last = "LastNameHere", bool is_provided = false) {
    if (!is_provided) {
      printf("Enter the last name: ");
      std::getline(cin, last);
      return this->last_name = last;
    } else {
      return this->last_name = last;
    }
  }
  int set_standard(int standard = 0, bool is_provided = false) {
    if (!is_provided) {
      printf("Enter the standard: ");
      scanf("%d", &standard);
      return this->standard = standard;
    } else {
      return this->standard = standard;
    }
  }
  int get_age() { return this->age; }
  string get_first_name() { return this->first_name; }
  string get_last_name() { return this->last_name; }
  int get_standard() { return this->standard; }
};

int main() {

  Student student;
  student.set_age();
  student.set_first_name();
  student.set_last_name();
  student.set_standard();

  printf("%d\n", student.get_age());
  printf("%s, %s\n", student.get_last_name().c_str(),
         student.get_first_name().c_str());
  printf("%d", student.get_standard());
  std::cout << '\n';
  std::cout << student.get_age() << "," << student.get_first_name() << ","
            << student.get_last_name() << "," << student.get_standard();
  return 0;
}
