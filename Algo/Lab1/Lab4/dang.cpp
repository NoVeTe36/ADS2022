#include <bits/stdc++.h>

using namespace std;

int check_prime(int m){
   for (int i = 2; i <= sqrt(m); i++){                         
    if (m % i == 0){
        return 0;   
    }
   } return 1;
}  //Complexity: sqrt(m)

int check_sphenic(int n, int m, int count) {
    m --;
    if (n == 1){
        if(count == 3){
            return 1;
        } else return 0;
    } else {
        if(check_prime(m) == 1 && (n % m) == 0) {         
            if (n % (m*m) == 0){
                return 0;
            } else {
                count ++;
                check_sphenic(n/m, m, count);
                }
        } else{
            check_sphenic(n, m, count);
        }
    }
} //Complexity: m*sqrt(m) = n*sqrt(n), with m = n

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int count = 0;
    if (check_sphenic(n, n, count) == 1){
        cout << n << " is a sphenic number.";
    } else {
        cout << n << " is not a sphenic number.";
    }
}