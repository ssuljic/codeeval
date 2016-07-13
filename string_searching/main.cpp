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

bool search_substr(const string& sentence, const string& substring) {
    int i(0);
    int j(0);
    while(i < sentence.size()) {
        if(sentence[i] == substring[j] || substring[j] == '*' || substring[j] == '\\') {
            int start = i;
            for(;;) {
                if(j == substring.size()) return true;
                if(i == sentence.size()) return false;

                if(substring[j] == '*') {
                    j++;
                    if(j == substring.size()) return true;

                    while(sentence[i] != substring[j]) {
                        if(i == sentence.size()) return false;
                        i++;
                    }
                } else if(substring[j] == '\\' && substring[j+1] == '*') {
                    j++;
                }

                if(sentence[i] != substring[j]) {
                    start = i;
                    j = 0;
                    break;
                }

                i++;
                j++;
            }
        }
        i++;
    }
    return false;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> parts = split(line, ',');
        if(search_substr(parts[0], parts[1])) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}