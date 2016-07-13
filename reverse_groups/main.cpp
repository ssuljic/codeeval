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
      vector<string> parts = split(line, ';');
      int k = atoi(parts[1].c_str());
      vector<string> numbers = split(parts[0], ',');
      vector<int> stack;
      vector<int> result;
      for(int i=0; i<numbers.size(); i++) {
        if(stack.size() == k) {
          while(stack.size() != 0) {
            int b = stack.back();
            result.push_back(b);
            stack.pop_back();
          }
        }
        int num = atoi(numbers[i].c_str());
        stack.push_back(num);
      }
      if(stack.size() == k) {
        while(stack.size() != 0) {
          int b = stack.back();
          result.push_back(b);
          stack.pop_back();
        }
      } else {
        for(int i=0; i<stack.size(); i++) {
          result.push_back(stack[i]);
        }
      }
      for(int i=0; i<result.size(); i++) {
        cout << result[i];
        if(i != result.size() - 1) cout << ",";
      }
      cout << endl;
    }
    return 0;
}