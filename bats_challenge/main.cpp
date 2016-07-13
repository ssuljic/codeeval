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

void use(int index, vector<bool>& used, int d) {
    int end = index + d;
    int start = index - d + 1;
    if(end > used.size()) end = used.size();
    if(start < 0) start = 0;
    for(int i=start; i<end; i++) {
        used[i] = true;
    }
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int DISTANCE_TO_WALL = 6;

    while (getline(stream, line)) {
        vector<int> nums = get_number_vector(split(line, ' '));
        int l = nums[0];
        int d = nums[1];
        int start = DISTANCE_TO_WALL;
        int end = l - DISTANCE_TO_WALL;

        nums.erase(nums.begin());
        nums.erase(nums.begin());
        nums.erase(nums.begin());
        int count = 0;
        vector<bool> used(l+1, false);

        for(int i=0; i<DISTANCE_TO_WALL; i++) {
            used[i] = true;
        }

        for(int i=l-DISTANCE_TO_WALL+1; i<l; i++) {
            used[i] = true;
        }

        for(int i=0; i<nums.size(); i++) {
            use(nums[i], used, d);
        }

        for(int i=1; i<l; i++) {
            if(!used[i]) {
                count++;
                use(i, used, d);
            }
        }

        cout << count << endl;
    }
    return 0;
}

// 22 2
// 6 9 11 13 15