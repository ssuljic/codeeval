#include <iostream>
#include <fstream>
#include <vector>

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

class RomanNumberal {
    string numeral;
public:
    void add(int digit, int unit) {
        if(unit == 0) {
            add_thousands(digit);
        } else if(unit == 1) {
            add_hundreds(digit);
        } else if(unit == 2) {
            add_tens(digit);
        } else {
            add_ones(digit);
        }
    }

    void add_thousands(int digit) {
        for(int i=0; i<digit; i++) {
            numeral += "M";
        }
    }

    void add_hundreds(int digit) {
        if(digit == 9) {
            numeral += "CM";
            return;
        } else if(digit == 4) {
            numeral += "CD";
            return;
        } else if(digit >= 5) {
            numeral += "D";
            digit -= 5;
        }
        for(int i=0; i<digit; i++) {
            numeral += "C";
        }
    }

    void add_tens(int digit) {
        if(digit == 9) {
            numeral += "XC";
            return;
        } else if(digit == 4) {
            numeral += "XL";
            return;
        } else if(digit >= 5) {
            numeral += "L";
            digit -= 5;
        }
        for(int i=0; i<digit; i++) {
            numeral += "X";
        }
    }

    void add_ones(int digit) {
        if(digit == 9) {
            numeral += "IX";
            return;
        } else if(digit == 4) {
            numeral += "IV";
            return;
        } else if(digit >= 5) {
            numeral += "V";
            digit -= 5;
        }
        for(int i=0; i<digit; i++) {
            numeral += "I";
        }
    }

    string get_numeral() {
        return numeral;
    }
};

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int num = atoi(line.c_str());
        vector<int> digits = extract_digits(num);
        RomanNumberal roman;
        for(int i=0; i<digits.size(); i++) {
            roman.add(digits[i], 4 - digits.size() + i);
        }
        cout << roman.get_numeral() << endl;
    }
    return 0;
}