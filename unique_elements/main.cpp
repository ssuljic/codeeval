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

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> numbers = split(line, ',');
        int num = atoi(numbers[0].c_str());
        vector<int> results;
        results.push_back(num);
        for(int i=1; i<numbers.size(); i++) {
            int n = atoi(numbers[i].c_str());
            if(n != num) {
                results.push_back(n);
                num = n;
            }
        }
        for(int i=0; i<results.size(); i++) {
            cout << results[i];
            if(i != results.size() - 1) cout << ",";
        }
        cout << endl;
    }
    return 0;
}