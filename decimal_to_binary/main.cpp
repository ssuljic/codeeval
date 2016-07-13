#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int n = atoi(line.c_str());
        string binary;
        if(n == 0) binary = "0";
        while (n) {
            if (n & 1) {
                binary.insert(0, 1, '1');
            }
            else {
                binary.insert(0, 1, '0');
            }
            n >>= 1;
        }
        cout << binary << endl;
    }
    return 0;
}