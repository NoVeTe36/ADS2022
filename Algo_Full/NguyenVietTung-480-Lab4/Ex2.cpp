#include<iostream>

using namespace std;

int SumOfDigits(int n){
    if (n == 0) {
        return 0;
    }
    else {
        return n % 10 + SumOfDigits(n / 10);
    }
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Sum of digits: " << SumOfDigits(n);
    return 0;
}