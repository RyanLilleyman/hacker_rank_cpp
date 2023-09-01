#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'gradingStudents' function below.
 *
 * the function  is expected to return an integer array
 *
 * the function accepts integer array grades as parameter.
 */

vector<int> gradingStudents(vector<int> grades) {
  for (int i = 0; i < grades.size(); i++) {
    if (grades[i] <= 40 && grades[i] < 38) {
      continue;
    } else if (grades[i] % 5 >= 3) {
      grades[i] = grades[i] + (5 - grades[i] % 5);
    }
  }
  return grades;
}

int main() {

  ofstream fout(getenv("OUTPUT_PATH"));
  string gradesCountTemp;
  getline(cin, gradesCountTemp);

  int gradesCount = stoi(ltrim(rtrim(gradesCountTemp)));

  vector<int> grades(gradesCount);

  for (int i = 0; i < gradesCount; i++) {
    string gradesItemTemp;
    getline(cin, gradesItemTemp);

    int gradesItem = stoi(ltrim(rtrim(gradesItemTemp)));

    grades[i] = gradesItem;
  }

  vector<int> result = gradingStudents(grades);
  for (size_t i = 0; i < result.size(); i++) {
    fout << result[i];
    if (i != result.size() - 1) {
      fout << "\n";
    }
  }

  fout << "\n";
  fout.close();
  return 0;
}

string ltrim(const string &str) {
  string s(str);
  s.erase(s.begin(), find_if(s.begin(), s.end(),
                             [](unsigned char c) { return !isspace(c); }));

  return s;
}

string rtrim(const string &str) {
  string s(str);
  s.erase(
      find_if(s.rbegin(), s.rend(), [](unsigned char c) { return !isspace(c); })
          .base(),
      s.end());

  return s;
}
