#include <iostream>
#include <string>
using namespace std;

int main() {
  size_t words = 0, sum = 0;
  cin >> words;
  string str;
  for (size_t i = 0; i < words; i++) {
    cin >> str;
    if (sum + 1 + str.size() > 80) {
      cout << endl;
      sum = 0;
    } else if (i > 0) {
      cout << " ";
      sum++;
    }
    cout << str;
    sum += str.size();
  }
  return 0;
}

