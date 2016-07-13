#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int sumOfSqDigits(int num) {
  int sum = 0;
  while(num != 0) {
    int digit = num % 10;
    sum += digit * digit;
    num /= 10;
  }
  return sum;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        map<int, int> steps;
        int num = atoi(line.c_str());
        while(num != 1) {
            if(steps[num] == 1) {
                cout << 0 << endl;
                break;
            }
            steps[num] = 1;
            num = sumOfSqDigits(num);
        }
        if(num == 1) {
            cout << 1 << endl;
        }
    }
    return 0;
}