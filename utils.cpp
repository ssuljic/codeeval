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

vector<int> extract_digits(int num) {
    vector<int> digits;
    while(num != 0) {
        int digit = num % 10;
        num /= 10;
        digits.insert(digits.begin(), digit);
    }
    return digits;
}

string trim(string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

bool isLowerLetter(char c) {
    return c >= 'a' && c <= 'z';
}

bool isUpperLetter(char c) {
    return c >= 'A' && c <= 'Z';
}

char toLower(char c) {
    if(isUpperLetter(c)) return c + 'a' - 'A';
    return c;
}

char toUpper(char c) {
    if(isLowerLetter(c)) return c - 'a' + 'A';
    return c;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int num = atoi(line.c_str());
    }
    return 0;
}