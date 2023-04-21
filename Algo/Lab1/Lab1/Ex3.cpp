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
