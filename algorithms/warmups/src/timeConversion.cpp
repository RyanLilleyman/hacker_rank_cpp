#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * the function is expected to return a STRING.
 * the function accepts a string s as a parameter.
 */
string timeConversion(string s) {
  int hour = std::stoi(s.substr(0, 2));
  string minutes = s.substr(3, 2);
  string seconds = s.substr(6, 2);
  string period = s.substr(8, 2);

  if (period == "PM" && hour != 12) {
    hour += 12;
  } else if (period == "AM" && hour == 12) {
    hour = 0;
  }

  char buffer[9];
  sprintf(buffer, "%02d:%02d:%02d", hour, stoi(minutes), stoi(seconds));
  return string(buffer);
}

int main() {
  ofstream fout(getenv("OUTPUT_PATH"));

  string s;
  getline(cin, s);

  string result = timeConversion(s);
  fout << result << "\n";
  fout.close();
  return 0;
}
