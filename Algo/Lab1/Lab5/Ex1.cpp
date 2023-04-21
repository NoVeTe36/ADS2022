#include<iostream>

using namespace std;

void swap1(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void sort(int a[], int n){

    int initial = 0;
    int final = n-1;
    bool swap_approved = true;
    while (swap_approved == true) {
        swap_approved = false;          // reset swap_approved to false
        for ( int i = initial; i < final; i++ ){
            if ( a[i] > a[i+1] ){
                swap1(a[i], a[i+1]);
                swap_approved;
            }
        }
        if (swap_approved == false){
            break;
            final--;
        }     
        for ( int i = final; i < initial; i++ ){
            if ( a[i] < a[i+1]){
                swap1(a[i], a[i+1]);
                swap_approved == true;
            }
        }
        initial++;
    }
}

void display(int a[], int n){
    cout << "\nThe array after: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}

int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "The array before: ";
    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    sort(a, n);
    display(a, n);
}


/* Pseudo code:
    1. Set initial = 0, final = n-1, swap_approved = true
    2. Sort function
    While swap_approved == true:
        2.1. Set swap_approved = false
        2.2. For i = initial to final:
            2.2.1. If a[i] > a[i+1]:
        2.3 If swap_approved == false:
            2.3.1. Break
            2.3.2. Set final = final - 1
        2.4 For i = final to initial:
            2.3.1. If a[i] < a[i+1]:
    3. main
        3.1. Input n
        3.2. Input a[n]
        3.3. Display a[n]
        3.4. Call sort function
        3.5. Display a[n]
*/

/*
Complexity:
    1. Time average complexity: O(n^2)
    2. Time worst case complexity: O(n^2)
    3. Time best case complexity: O(n)
*/