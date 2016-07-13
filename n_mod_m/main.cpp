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
        vector<string> nums = split(line, ',');
        int n = atoi(nums[0].c_str());
        int m = atoi(nums[1].c_str());
        int temp = m;
        while(temp <= n) {
            temp += m;
        }
        cout << (n - temp + m) << endl;
    }
    return 0;
}