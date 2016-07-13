#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

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

string join(vector<int> vec, char c) {
    string result;
    for(int i=0; i<vec.size(); i++) {
        string ch = to_string(vec[i]);
        result += ch;
        if(i != vec.size() - 1) result.push_back(c);
    }
    return result;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> sets = split(line, ';');
        vector<int> set1 = get_number_vector(split(sets[0], ','));
        vector<int> set2 = get_number_vector(split(sets[1], ','));
        vector<int> results;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(results));
        cout << join(results, ',') << endl;
    }
    return 0;
}