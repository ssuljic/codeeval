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

string trim(string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      vector<string> parts = split(line, ',');
      string chars_to_remove = trim(parts[1]);
      string sentence = parts[0];
      for(int i=0; i<sentence.length(); i++) {
        bool print = true;
        for(int j=0; j<chars_to_remove.length(); j++) {
          if(sentence[i] == chars_to_remove[j]) {
            print = false;
            break;
          }
        }
        if(print) {
          cout << sentence[i];
        }
      }
      cout << "\n";
    }
    return 0;
}