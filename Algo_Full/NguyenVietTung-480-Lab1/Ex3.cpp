#include<iostream>

using namespace std;

int MaxOfArray(int &max, int a) {
    if (max < a) {
        max = a;
    }
    return max;
}

int main() {
    int NumberOfInt;
    cout << "Number of int in array is: "; 
    cin >> NumberOfInt;
    int Test = 0;
    int max = Test; 
    for (int i = 0; i < NumberOfInt; i++) {
        cin >> Test; 
        MaxOfArray(max, Test);
    }
    cout << "Max of array is: " << max << endl;
    return 0;
}

/* Complexity: n

In main, enter number of numbers in array and set max to a between-value 
Enter the particle in array, each time enter a number, it will call out function MaxOfArray and compare them 2, if the newly entered is greater than max, max will be set = the number just enter
else max stays max.
-> n times it call MaxOfArray -> big O = n

*/