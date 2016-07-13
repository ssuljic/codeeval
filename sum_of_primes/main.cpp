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

int main() {
    int prime_counter = 0;
    int i = 1;
    int sum = 0;
    while(prime_counter != 1000) {
        if(isPrime(i)) {
            sum += i;
            prime_counter++;
        }
        i++;
    }
    cout << sum;
    return 0;
}