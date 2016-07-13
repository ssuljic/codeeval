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

string trim(string& str, char delimiter) {
    size_t first = str.find_first_not_of(delimiter);
    size_t last = str.find_last_not_of(delimiter);
    return str.substr(first, (last-first+1));
}

struct Point {
    int x;
    int y;
};

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<Point> points;
        int i=0;
        while(i < line.size()) {
            if(line[i] == '(') {
                i++;
            }

        }
    }
    return 0;
}