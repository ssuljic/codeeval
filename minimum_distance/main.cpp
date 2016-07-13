#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
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

vector<int> get_number_vector(vector<string> vec) {
    vector<int> results;
    for(int i=0; i<vec.size(); i++) {
        results.push_back(atoi(vec[i].c_str()));
    }
    return results;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<int> numbers = get_number_vector(split(line, ' '));
        int min = -1;
        for(int i=1; i<numbers.size(); i++) {
            int sum = 0;
            for(int j=1; j<numbers.size(); j++) {
                if(i == j) continue;
                sum += abs(numbers[i] - numbers[j]);
            }
            if(min == -1 || sum < min) min = sum;
        }
        cout << min << endl;
    }
    return 0;
}