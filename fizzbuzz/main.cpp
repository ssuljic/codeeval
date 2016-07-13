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
      int a = atoi(parts[0].c_str());
      int b = atoi(parts[1].c_str());
      int end = atoi(parts[2].c_str());

      for(int i=1; i<=end; i++) {
        if(i % a == 0) cout << 'F';
        if(i % b == 0) cout << 'B';
        if(i % b != 0 && i % a != 0) cout << i;
        cout << " ";
      }
      cout << "\n";
    }
    return 0;
}