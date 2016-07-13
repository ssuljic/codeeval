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

struct Pair {
    int first;
    int second;
};

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> parts = split(line, ';');
        int number = atoi(parts[1].c_str());
        vector<string> numbers = split(parts[0], ',');
        vector<Pair> results;
        for(int i=0; i<numbers.size() - 1; i++) {
            int num1 = atoi(numbers[i].c_str());
            for(int j=i+1; j<numbers.size(); j++) {
                int num2 = atoi(numbers[j].c_str());
                if(num2 > number - num1) break;
                if(num2 == number - num1) {
                    Pair pair = { num1, num2 };
                    results.push_back(pair);
                }
            }
        }
        if(results.size() == 0) cout << "NULL";
        for(int i=0; i<results.size(); i++) {
            cout << results[i].first << "," << results[i].second;
            if(i != results.size() - 1) cout << ";";
        }
        cout << endl;
    }
    return 0;
}