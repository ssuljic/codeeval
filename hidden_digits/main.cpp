#include <iostream>
#include <fstream>
#include <map>

using namespace std;


bool isNumeric(char c) {
    return c >= '0' && c <= '9';
}

int main(int argc, char *argv[]) {
    map<char, int> data;
    data['a'] = 0;
    data['b'] = 1;
    data['c'] = 2;
    data['d'] = 3;
    data['e'] = 4;
    data['f'] = 5;
    data['g'] = 6;
    data['h'] = 7;
    data['i'] = 8;
    data['j'] = 9;
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        bool none = true;
        for(int i=0; i<line.size(); i++) {
            map<char, int>::iterator it = data.find(line[i]);
            if(it != data.end()) {
                none = false;
                cout << data[line[i]];
            } else if(isNumeric(line[i])) {
                none = false;
                cout << line[i];
            }
        }
        if(none) cout << "NONE";
        cout << endl;
    }
    return 0;
}