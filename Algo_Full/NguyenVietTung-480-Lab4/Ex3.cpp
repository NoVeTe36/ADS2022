#include<iostream>
#include<math.h>

using namespace std;

int isPrime(int n) {        // Complexity: sqrt(n)
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



int checkSphenic(int n, int count, int a) {       // Complexity: a
    if (a < 2) {
        return count;
    }
    int product = n;
    if (n % a == 0 && n % (a*a) != 0 && isPrime(a) == 1) {
        count++;
        product /= a;
        checkSphenic(product , count, a - 1);
    }
    else {
        checkSphenic(n, count, a - 1);
    }
}


int main(){
	while(1){
		int n;
    	cout << "Enter number: ";
    	cin >> n;
    	int count = 0;
    	if (checkSphenic(n, count, n) == 3) {
        	cout << n << " is a sphenic number.\n";
    	}
    	else {
        	cout << n << " is not a sphenic number.\n";
    	}	
	}
}


// Complexity: sqrt(n) * a  with a here = n => Complexity: sqrt(n) * n = n * sqrt(n) = O(n * sqrt(n))
