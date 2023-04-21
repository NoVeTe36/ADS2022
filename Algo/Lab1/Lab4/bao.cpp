#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
                break;
            }
        }
        return true ;
    }
}

bool isSphenic(int n, int divisors, int a) {
    if (a > sqrt(n))
        return divisors;
    if (n % a == 0 && isPrime(a) == true && n % (a*a) != 0) {
        divisors++;
        n /= a;
        return isSphenic(n , divisors, a + 1);
    }
    else {
        return isSphenic(n, divisors, a + 1);
    }
    
    if (divisors == 3 && n == 1) 
        return true;
    else 
        return false;
}


int main(){
    int n;
    cout << "Enter number: ";
    cin >> n;
    int divisors = 0;
    if (isSphenic(n, divisors, 2) == true ) {
        cout << n << " is a sphenic number.";
    }
    else {
        cout << n << " is not a sphenic number.";
    }
}