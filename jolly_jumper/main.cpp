#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
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

void is_jolly(map<int, int> counters, int n) {
    for(int i=1; i<n; i++) {
        if(counters[i] == 0) {
            cout << "Not jolly" << endl;
            return;
        }
    }
    cout << "Jolly" << endl;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    while (getline(stream, line)) {
        map<int, int> counters;
        vector<string> numbers = split(line, ' ');
        int n = atoi(numbers[0].c_str());
        // Init map
        for(int i=1; i<n; i++) {
            counters[i] = 0;
        }
        for(int i=2; i<numbers.size(); i++) {
            int prev = atoi(numbers[i-1].c_str());
            int num = atoi(numbers[i].c_str());
            int diff = abs(num - prev);
            counters[diff]++;
        }

        is_jolly(counters, n);
    }
    return 0;
}