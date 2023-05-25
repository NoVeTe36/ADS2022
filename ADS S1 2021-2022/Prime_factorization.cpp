#include<iostream>
#include<math.h>

using namespace std;

// bool isPrime(int a) {
//     int count = 0;
//     if (a == 1 || a == 0) {
//         return 0;
//     }
//     for (int i = 2; i <= sqrt(a); i++) {
//         if (a % i == 0) {
//             count++;
//         }
//     }
//     if (count == 0) {
//         return true;
//     }
//     if (count != 0) {
//         return false;
//     }
// }

void factorization(int n, int count) {
    if (n < 1){
        return;
    }
    if (n % count == 0) {
        cout << "*" << count;
        factorization(n/count, count);
    }
    else {
        factorization(n, ++count);
    }
}

int main(){
    int n;
    cin >> n;
    cout << "1";
    factorization(n, 2);
}