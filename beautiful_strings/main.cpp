#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool isLowerLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpperLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

bool isLetter(char c) {
    return isLowerLetter(c) || isUpperLetter(c);
}

char toLower(char c) {
    if(isUpperLetter(c)) return c + 'a' - 'A';
    return c;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        map<char, int> counters;
        for(int i=0; i<line.size(); i++) {
            if(!isLetter(line[i])) continue;
            counters[toLower(line[i])]++;
        }

        vector<int> v;
        for(map<char, int>::iterator it = counters.begin(); it!=counters.end(); it++) {
            v.push_back(it->second);
        }
        sort(v.begin(), v.end(), greater<int>());
        int score = 26;
        int beauty = 0;
        for(int i=0; i<v.size(); i++) {
            beauty += v[i] * score;
            score--;
        }
        cout << beauty << endl;
    }
    return 0;
}