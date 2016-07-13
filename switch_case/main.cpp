#include <iostream>
#include <fstream>
using namespace std;

bool isLowerLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpperLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

char toLower(char c) {
    if(isUpperLetter(c)) return c + 'a' - 'A';
    return c;
}

char toUpper(char c) {
    if(isLowerLetter(c)) return c - 'a' + 'A';
    return c;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    while (getline(stream, line)) {
        for(int i=0; i<line.size(); i++) {
            if(isLowerLetter(line[i])) {
                cout << toUpper(line[i]);
            } else if(isUpperLetter(line[i])) {
                cout << toLower(line[i]);
            } else {
                cout << line[i];
            }
        }
        cout << endl;
    }
    return 0;
}