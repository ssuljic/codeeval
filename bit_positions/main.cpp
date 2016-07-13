#include <iostream>
#include <fstream>
#include <bitset>
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

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<int> nums = get_number_vector(split(line, ','));
        string binary;
        if(nums[0] == 0) binary = "0";
        while (nums[0]) {
            if (nums[0] & 1) {
                binary.insert(0, 1, '1');
            }
            else {
                binary.insert(0, 1, '0');
            }
            nums[0] >>= 1;
        }
        if(binary[binary.size() - nums[1]] == binary[binary.size() - nums[2]]) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}