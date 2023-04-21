#include<iostream>

using namespace std;

void insertArray(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << "Insert element " << i + 1 << ": ";
        cin >> arr[i];
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    int *p = &arr[0];
    insertArray(arr, n);
    for (int i = 0; i < n; i++){
        cout << *(p + i) << " ";
    }
   return 0;
}