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

struct Point {
    int x;
    int y;
};

struct Rectangle {
    Point upper_left;
    Point lower_right;
};

bool overlap(Rectangle a, Rectangle b) {
    if(a.upper_left.x > b.lower_right.x || a.lower_right.x < b.upper_left.x) return false;
    if(a.upper_left.y < b.lower_right.y || a.lower_right.y > b.upper_left.y) return false;
    return true;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        vector<int> coordinates = get_number_vector(split(line, ','));
        Rectangle a, b;

        Point p1 = { coordinates[0], coordinates[1] };
        Point p2 = { coordinates[2], coordinates[3] };
        Point p3 = { coordinates[4], coordinates[5] };
        Point p4 = { coordinates[6], coordinates[7] };

        a.upper_left = p1;
        a.lower_right = p2;

        b.upper_left = p3;
        b.lower_right = p4;

        if(overlap(a, b)) {
            cout << "True" << endl;
        } else {
            cout << "False" << endl;
        }
    }
    return 0;
}