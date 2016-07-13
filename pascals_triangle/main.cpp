#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;

    while (getline(stream, line)) {
        int n = atoi(line.c_str());
        vector<vector<int> > pascal(n, vector<int>(n));
        for(int i=0; i<n; i++) {
            pascal[i][0] = 1;
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<=i; j++) {
                pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                cout << pascal[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}