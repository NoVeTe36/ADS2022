#include<iostream>
#include<math.h>

using namespace std;

// void swap(int *x, int *y){
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// void sort(int arr[], int n){
//     for (int i = 0; i < n; i++) {
//         for (int j = i+1; j < n; j++) {
//             if (arr[j] < arr[i]) {
//                 swap(&arr[j], &arr[i]);
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

//3 4 5 9 10 15 27 40 45

void checkTriplet(int arr[], int n){
    for(int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n; j++){
            for (int k = j+1; k < n-1; k++){
                if (arr[i] % arr[j] == 0){
                    int temp = arr[i]/arr[j];
                    if (temp == arr[k]) {
                        cout << arr[i] << "=" << arr[j] << "*" << temp << endl;
                    }
                }
            }
        }
    }
}

int main(){
    int n;
    cout << "Enter number of elements: "; 
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // sort(arr, n);
    checkTriplet(arr, n);
    return 0;
}