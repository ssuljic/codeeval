#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

vector<int> extract_digits(int num) {
  vector<int> digits;
  while(num != 0) {
    int digit = num % 10;
    num /= 10;
    digits.insert(digits.begin(), digit);
  }
  return digits;
}

void print_self_describing(vector<int> digits, map<int, int> counters) {
    for(int i=0; i<digits.size(); i++) {
        if(counters[i] != digits[i]) {
            cout << 0;
            return;
        }
    }
    cout << 1;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int num = atoi(line.c_str());
        vector<int> digits = extract_digits(num);
        map<int, int> counters;

        for(int i=0; i<digits.size(); i++) {
            counters[digits[i]]++;
        }

        print_self_describing(digits, counters);
        cout << endl;
    }
    return 0;
}