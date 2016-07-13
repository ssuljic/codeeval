#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        map<char, int> counters;
        vector<char> characters;
        for(int i=0; i<line.size(); i++) {
            counters[line[i]]++;
            characters.push_back(line[i]);
        }
        for(int i=0; i<characters.size(); i++) {
            if(counters[characters[i]] == 1) {
                cout << characters[i] << endl;
                break;
            }
        }
    }
    return 0;
}