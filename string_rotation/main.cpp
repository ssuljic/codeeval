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

bool is_rotated(const string& word1, const string& word2) {
    if(word1.size() != word2.size()) return false;

    for(int i=0; i<word2.size(); i++) {
        if(word1[0] == word2[i]) {
            int start = i;
            bool matched = true;
            for(int j=0; j<word1.size(); j++) {
                if(word1[j] != word2[i % word2.size()]) {
                    matched = false;
                    break;
                }
                i++;
            }
            if(matched) return true;
            i = start;
        }
    }

    return false;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> parts = split(line, ',');
        if(is_rotated(parts[0], parts[1])) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}