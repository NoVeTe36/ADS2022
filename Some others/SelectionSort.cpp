#include<iostream>

using namespace std;

int swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array before sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    int key;
    for (int i = 0; i < n; i++) {
        key = i;
        for (int j = i+1; j < n; j++) {
            if (arr[key] > arr[j]) {
                key = j;
            }
        }
        if (key != i){
            swap(&arr[key], &arr[i]);
        }
    }
    cout << "\nArray after sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}