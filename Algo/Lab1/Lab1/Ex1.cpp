#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int a) {
    int count = 0;
    if (a == 1 || a == 0) {
        return 0;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        return true;
    }
    if (count != 0) {
        return false;
    }
}

int checkSphenic(int n) {
    int count = 0;
    int plus = 0;
    int arr[1000] = {};
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            arr[plus] = i;
            plus++;
        }
    }
    if (plus == 8) {
        for(int plus = 0; plus <= 5; plus++) {
            if (isPrime(arr[plus]) == true ) {
                count++;
            } 
        }
        if (count == 3) {
            return 1;
        }
    }
} 

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if(checkSphenic(n) == 1) {
        cout << "A sphenic number." << endl;
    }
    else {
        cout << "Not a sphenic number." << endl;
    }
    return 0;
}