#include <iostream>
#include <fstream>
using namespace std;

int reverse(int number) {
    int reverse = 0, copy = number;
    while(copy != 0) {
        reverse = reverse * 10 + copy % 10;
        copy /= 10;
    }
    return reverse;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int num = atoi(line.c_str());
        int rev = reverse(num);
        int i = 0;
        while(rev != num) {
            num += rev;
            rev = reverse(num);
            i++;
        }
        cout << i << " " << num << "\n";
    }
    return 0;
}