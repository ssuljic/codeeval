#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

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
    map<string, int> mapping;
    mapping["zero"] = 0;
    mapping["one"] = 1;
    mapping["two"] = 2;
    mapping["three"] = 3;
    mapping["four"] = 4;
    mapping["five"] = 5;
    mapping["six"] = 6;
    mapping["seven"] = 7;
    mapping["eight"] = 8;
    mapping["nine"] = 9;
    while (getline(stream, line)) {
        vector<string> numbers = split(line, ';');
        for(int i=0; i<numbers.size(); i++) cout << mapping[numbers[i]];
        cout << endl;
    }
    return 0;
}