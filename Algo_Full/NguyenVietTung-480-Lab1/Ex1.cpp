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


/*complexity: O() = n^2 

Pseudocode:


Function1: check prime
Count the number of divisors of input n from 2 to square root of n
if count = 0 -> true (is prime)
if count !=0 -> false (not a prime)

Function2: check number of prime divisors
A sphenic number has 8 divisors(1, itself, 3 prime numbers and its combinations)
So i check all of it divisors from 1 to n/2 (because n/2 is min natural number) and put it into an array
Next i check the first 5 numbers of array and check if there are 3 prime numbers.
if there are -> return 1
if not -> return 0

Main: 
if n satisfied Function 2 -> print "n is sphenic number."
else print "n is not sphenic number"
*/