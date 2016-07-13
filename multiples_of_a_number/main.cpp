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
      int a = atoi(strings[0].c_str());
      int b = atoi(strings[1].c_str());
      int temp = b;
      while(temp < a) {
        temp += b;
      }
      cout << temp << "\n";
    }
    return 0;
}