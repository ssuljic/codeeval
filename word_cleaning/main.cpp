#include <iostream>
#include <fstream>

using namespace std;

bool isCharacter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

char toLower(char c) {
    if(!isCharacter(c)) {
        return c;
    }
    if(c >= 'a' && c <= 'z') {
        return c;
    }
    return c + 'a' - 'A';
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    while(getline(stream, line)) {
        for(int i=0; i<line.size(); i++) {
            if(isCharacter(line[i])) {
                cout << toLower(line[i]);
            } else if(i != 0 && isCharacter(line[i-1])) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}