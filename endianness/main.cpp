#include <iostream>
using namespace std;

int main() {
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01020304};

    cout << ((bint.c[0] == 1) ? "BigEndian" : "LittleEndian");
    return 0;
}