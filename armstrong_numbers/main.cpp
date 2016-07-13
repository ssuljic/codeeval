#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int num = atoi(line.c_str());
        vector<int> digits = extract_digits(num);
        int sum = 0;
        for(int i=0; i<digits.size(); i++) {
            sum += pow(digits[i], digits.size());
        }
        if(sum == num) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}