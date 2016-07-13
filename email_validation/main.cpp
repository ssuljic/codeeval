#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    regex email_regex("[a-zA-Z1-9_-]+@[a-zA-Z1-9_-]+\\.[a-zA-Z1-9_-]{2,4}", regex_constants::ECMAScript);
    while (getline(stream, line)) {
        if(line.size() == 0) continue;
        bool valid = regex_match(line, email_regex);
        cout << (valid ? "true" : "false") << endl;
    }
    return 0;
}