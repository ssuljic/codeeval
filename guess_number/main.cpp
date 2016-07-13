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
      vector<string> parts = split(line, ' ');
      int upper =  atoi(line.c_str());
      int lower = 0;
      int median = (upper + lower + 1) / 2;
      int i = 1;
      while(parts[i] != "Yay!") {
        if(parts[i] == "Lower") {
            upper = median - 1;
        } else {
            lower = median + 1;
        }
        median = (upper + lower + 1) / 2;
        i++;
      }
      cout << median << "\n";
    }
    return 0;
}