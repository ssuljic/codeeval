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

string join(vector<char> vec, char c) {
    string result;
    for(int i=0; i<vec.size(); i++) {
        result += vec[i];
        if(i != vec.size() - 1) result.push_back(c);
    }
    return result;
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
        if(trim(line) == "") continue;
        vector<string> parts = split(line, '|');
        vector<char> writer;
        vector<string> positions = split(parts[1], ' ');
        for(int i=0; i<positions.size(); i++) {
            if(positions[i] == "") continue;
            int pos = atoi(trim(positions[i]).c_str());
            writer.push_back(parts[0][pos-1]);
        }
        for(int i=0; i<writer.size(); i++) cout << writer[i];
        cout << endl;
    }
    return 0;
}