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
      vector<int> stack;
      vector<string> strings = split(line, ' ');
      for(int i=0; i<strings.size(); i++) {
        stack.push_back(atoi(strings[i].c_str()));
      }
      int i = 0;
      while(stack.size() != 0) {
        int num = stack.back();
        stack.pop_back();
        if(i % 2 == 0) {
            cout << num << " ";
        }
        i++;
      }
      cout << "\n";
    }
    return 0;
}