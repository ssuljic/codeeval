#include <iostream>
#include <fstream>
using namespace std;

int sumOfDigits(int num) {
  int sum = 0;
  while(num != 0) {
    sum += num % 10;
    num /= 10;
  }
  return sum;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      int num = atoi(line.c_str());
      cout << sumOfDigits(num) << "\n";
    }
    return 0;
}