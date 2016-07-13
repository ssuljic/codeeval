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

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<int> numbers = get_number_vector(split(line, ' '));
        int min = -1;
        int min_index = 0;
        for(int i=0; i<numbers.size(); i++) {
            bool unique = true;
            for(int j=0; j<numbers.size(); j++) {
                if(i != j && numbers[i] == numbers[j]) {
                    unique = false;
                    break;
                }
            }
            if(unique && (min == -1 || numbers[i] < min)) {
                min = numbers[i];
                min_index = i + 1;
            }
        }
        cout << min_index << endl;
    }
    return 0;
}