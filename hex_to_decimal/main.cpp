#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int changeHex(char c) {
    int diff = c - 'a';
    return 10 + diff;
}

int main(int argc, char *argv[]) {
    int BASE = 16;
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int len = line.size();
        int sum = 0;
        for(int i=0; i<len; i++) {
            int num;
            if(line[i] >= '0' && line[i] <= '9') {
                num = line[i] - '0';
            } else {
                num = changeHex(line[i]);
            }
            sum += num * pow(BASE, len - 1 - i);
        }
        cout << sum << endl;
    }
    return 0;
}