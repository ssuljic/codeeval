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

string trim(string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<string> parts = split(line, '|');
        vector<int> numbers = get_number_vector(split(trim(parts[0]), ' '));
        int iterations = atoi(trim(parts[1]).c_str());
        int swaps = 0;
        for(int i=0; i<numbers.size() -1; i++) {
            if(swaps == iterations) break;
            if(numbers[i] > numbers[i+1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = temp;
                swaps++;
                i=-1;
            }
        }
        for(int i=0; i<numbers.size(); i++) cout << numbers[i] << " ";
        cout << endl;
    }
    return 0;
}