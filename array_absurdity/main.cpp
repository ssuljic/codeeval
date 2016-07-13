#include <iostream>
#include <fstream>
#include <map>
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

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    while (getline(stream, line)) {
        map<int, int> counters;
        vector<string> parts = split(line, ';');
        int cap = atoi(parts[0].c_str());
        // Init map
        for(int i=0; i<cap; i++) {
            counters[i] = 0;
        }
        vector<string> numbers = split(parts[1], ',');
        for(int i=0; i<numbers.size(); i++) {
            int num = atoi(numbers[i].c_str());
            if(counters[num] == 0) {
                counters[num]++;
            } else {
                cout << num << endl;
                break;
            }
        }
    }
    return 0;
}