#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

bool isLowerLetter(char c) {
    return c >= 'a' && c <= 'z';
}

char toUpper(char c) {
    if(isLowerLetter(c)) return c - 'a' + 'A';
    return c;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> parts = split(line, ' ');
        for(int i=0; i<parts[0].size(); i++) {
            if(parts[1][i] == '1') {
                cout << toUpper(parts[0][i]);
            } else {
                cout << parts[0][i];
            }
        }
        cout << endl;
    }
    return 0;
}