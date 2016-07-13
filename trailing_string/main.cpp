#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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
      vector<string> strings = split(line, ',');
      size_t pos = strings[0].find(strings[1]);
      if(string::npos == pos || strings[0].substr(pos).compare(strings[1]) != 0) {
        cout << 0 << "\n";
      } else {
        cout << 1 << "\n";
      }
    }
    return 0;
}