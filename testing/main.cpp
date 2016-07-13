#include <iostream>
#include <fstream>
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

string trim(string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> parts = split(line, '|');
        string sent1 = trim(parts[0]);
        string sent2 = trim(parts[1]);
        int bugs = 0;
        for(int i=0; i<sent1.size(); i++) {
            if(sent1[i] != sent2[i]) {
                bugs++;
            }
        }
        if(bugs == 0) {
            cout << "Done" << endl;
        } else if(bugs <= 2) {
            cout << "Low" << endl;
        } else if(bugs <= 4) {
            cout << "Medium" << endl;
        } else if(bugs <= 6) {
            cout << "High" << endl;
        } else {
            cout << "Critical" << endl;
        }
    }
    return 0;
}