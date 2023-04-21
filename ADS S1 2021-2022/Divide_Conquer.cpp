/*Pseudocode: 
    Function check_prime(input: n)
        for i <- 2 to sqrt(n)
            if n % i = 0
            return false
    return true

    Function fac_div(input: n)
    if n = 1
        return false
    else 
        for i <- 1 to n do 1
            if n % i = 0 & i >= sqrt(n)
                d1 <- i;
                break the loop
        d2 <- n/d1
        if check_prime(d1) is false
            return fac_div(d1)
        else
            output: d1
        if check_prime(d2) is false
            return fac_div(d2)
        else 
            output: d2
    
*/

#include <bits/stdc++.h>
using namespace std;

int check_prime(int n){
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0){
            return 0;
        }
    } return 1;
}//Complexity: O(sqrt(n))

int fac_div(int n){
    if (n == 1){
        return 0;
    } else {
        int d1, d2;
        for (int i = 1; i < n; i++){
            if (n % i == 0 && i >= sqrt(n)){
                d1 = i;
                break;
            }
        }
        d2 = n/d1;
        if (check_prime(d1) == 0){
            fac_div(d1);
        } else {
            cout << d1 << " ";
        }
        if (check_prime(d2) == 0){
            fac_div(d2);
        } else {
            cout << d2 << " ";
        }
    }
}

int main(){
    int n;
    cin >> n;
    fac_div(n);
}