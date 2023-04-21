#include<iostream>
#include<math.h>

using namespace std;

int isPrime(int n) {
    if (n < 2) {
        return 0;
    }
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}

int checkSphenic(int n){
    int count = 0;
    int product = n;
    for (int i = 2; i < n/2; i++) {
        if (n % i == 0 && isPrime(i)) {
            if (n % (i*i) != 0) {
                count++;
                return checkSphenic(product /= i);
            }
        }
        if (n == 1){
            continue;
        }
    }
    if (count == 3 && product == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int n;
    cout << "Enter number n: ";
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (checkSphenic(i)) {
            cout << i << " ";
        }
    }
}