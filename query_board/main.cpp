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

void set_row(int (&board)[256][256], int row, int x) {
    for(int i=0; i<256; i++) {
        board[row][i] = x;
    }
}

void set_col(int (&board)[256][256], int col, int x) {
    for(int i=0; i<256; i++) {
        board[i][col] = x;
    }
}

int query_row(int (&board)[256][256], int row) {
    int sum = 0;
    for(int i=0; i<256; i++) {
        sum += board[row][i];
    }
    return sum;
}

int query_col(int (&board)[256][256], int col) {
    int sum = 0;
    for(int i=0; i<256; i++) {
        sum += board[i][col];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int board[256][256] = { {0} };
    while (getline(stream, line)) {
        vector<string> parts = split(line, ' ');
        if(parts[0] == "SetRow") {
            set_row(board, atoi(parts[1].c_str()), atoi(parts[2].c_str()));
        } else if(parts[0] == "SetCol") {
            set_col(board, atoi(parts[1].c_str()), atoi(parts[2].c_str()));
        } else if(parts[0] == "QueryRow") {
            cout << query_row(board, atoi(parts[1].c_str())) << endl;
        } else if(parts[0] == "QueryCol") {
            cout << query_col(board, atoi(parts[1].c_str())) << endl;
        }
    }
    return 0;
}