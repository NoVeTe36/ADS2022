#include<iostream>
#include<math.h>

using namespace std;

bool isPrime(int n) {
    int times = 1;
    for (int i = 2; i <= sqrt(n); i++) { 
        if (n % i == 0) {
            times += 1;
        }
    }
    if (times == 1) {
        return true;
    }
    else {
        return false;
    }
} //sqrt(n)

void SphenicNumbers(){
    int n;
    cout << "Enter n: ";
    cin >> n;
    int count = 0;
    int SphenicNumbers;
    for(int i=2; i < (n/2); i++){ //n/2
        for(int j=2; j < i; j++){  
            for(int k=2; k < j; k++){
                if (isPrime(i) == true && isPrime(j) == true && isPrime(k) == true) {
                    if (i != j && i != k && j != k ) {
                        if (i*j*k <= n) {
                            // count+= 1;
                            cout << i*j*k << " ";
                        }
                    }
                }       
            }
        }
    }
}

int main() {
    SphenicNumbers();
}
