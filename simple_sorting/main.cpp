#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
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
        vector<string> parts = split(line, ' ');
        vector<float> nums;
        for(int i=0; i<parts.size(); i++) {
            nums.push_back(atof(parts[i].c_str()));
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            cout << fixed << setprecision(3) << nums[i] << " ";
        }
        cout << endl;
    }
    return 0;
}