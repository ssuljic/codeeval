#include <iostream>
#include <fstream>

using namespace std;

bool isLetter(char c) {
    return c >= 'a' && c <= 'z';
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    string english = "abcdefghijklmnopqrstuvwxyz";
    string codel   = "yhesocvxduiglbkrztnwjpfmaq";
    while (getline(stream, line)) {
        for(int i=0; i<line; i++) {
            if(isLetter(line[i])) {

            }
        }
    }
    return 0;
}