#include<iostream>

using namespace std;

int lengthOfInteger(int n){
    int length = 0;
    while(n > 0){
        n /= 10;
        length++;
    }
    return length;
}

void SumOfDigits(){
    int n;                                                  // 1
    cout << "Enter the number: ";                           // 1
    cin >> n;                                            // 1
    int sum = 0;                                           // 1
    cout << "Complexity of for loop is: " << lengthOfInteger(n) << endl; // 1
    for (int i = lengthOfInteger(n); i > 0; i--){                        // n
        int temp = 0;
        temp = n % 10;
        n /= 10;
        sum += temp;
    }
    cout << "Sum of digits: " << sum << endl;            // 1
}

int main(){
    SumOfDigits();
} 

/* Complexity: log10(n)

Pseudocode:
1. Read the number
2. Initialize sum = 0
3. For i = 0 to n
4.     sum += n % 10
5.     n /= 10
6. Print sum

*/

