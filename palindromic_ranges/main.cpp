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

bool is_palindrome(int number) {
    int reverse = 0, copy = number;
    while(copy != 0) {
        reverse = reverse * 10 + copy % 10;
        copy /= 10;
    }
    return number == reverse;
}

bool is_interesting(int start, int end) {
    int count = 0;
    for(int i=start; i<=end; i++) {
        if(is_palindrome(i)) count++;
    }
    return count % 2 == 0;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<int> input = get_number_vector(split(line, ' '));
        int start = input[0];
        int end = input[1];
        int count = 0;
        for(int i=start; i<= end; i++) {
            for(int j=i; j<= end; j++) {
                if(is_interesting(i, j)) count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}