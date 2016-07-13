#include <iostream>
#include <fstream>
#include <map>
using namespace std;

char toLower(char c) {
    if(c >= 'A' && c <= 'Z') return c + 'a' - 'A';
    return c;
}

bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    map<char, int> counters;
    char c = 'a';
    while(c != ('z' + 1)) {
        counters[c] = 0;
        c++;
    }

    while (getline(stream, line)) {
        for(int i=0; i<line.size(); i++) {
            if(isLetter(line[i])) {
                counters[toLower(line[i])]++;
            }
        }
        bool pangram = true;
        for(map<char, int>::iterator iterator = counters.begin(); iterator != counters.end(); iterator++) {
            if(iterator->second == 0) {
                pangram = false;
                cout << iterator->first;
            }
            iterator->second = 0;
        }
        if(pangram) cout << "NULL";
        cout << endl;
    }
    return 0;
}