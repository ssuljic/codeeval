#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

bool isLowerLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpperLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int lower = 0, upper = 0, total = 0;
        for(int i=0; i<line.size(); i++) {
            total++;
            if(isUpperLetter(line[i])) upper++;
            else lower++;
        }
        cout << fixed << setprecision(2) << "lowercase: " << lower * 100.0 / total << " uppercase: " << upper * 100.0 / total << endl;
    }
    return 0;
}