#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
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

bool isPrime(int n) {
    if(n < 2) return false;
    if(n < 4) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    int i = 5;
    while(i * i <= n) {
        if(n % i == 0 || n % (i+2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      vector<string> boundaries = split(line, ',');
      int start = atoi(boundaries[0].c_str());
      int end = atoi(boundaries[1].c_str());
      int count = 0;
      for(int i=start; i<=end; i++) {
        if(isPrime(i)) count++;
      }
      cout << count << "\n";
    }
    return 0;
}