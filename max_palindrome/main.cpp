#include <iostream>
#include <fstream>
using namespace std;

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

int reverse(int number) {
    int reverse = 0, copy = number;
    while(copy != 0) {
        reverse = reverse * 10 + copy % 10;
        copy /= 10;
    }
    return reverse;
}

int main() {
    for(int i=1000; i>=1; i--) {
        if(reverse(i) == i && isPrime(i)) {
            cout << i;
            break;
        }
    }
    return 0;
}