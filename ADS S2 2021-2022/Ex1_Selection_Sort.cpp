/*Pseudocode:
    Function selectionSort(input: array, n, start)
        if start = n - 2
            return false
        else
            min <- start
            for i <- start + 1 to n do 1
            if array[i] < array[min]
                min <- i
            if min != start
                swap(array[min], array[start])
            return selectionSort(array, n, start + 1)

*/

#include<bits/stdc++.h>

using namespace std;

int selectionSort(int arr[], int n, int start){
    if (start == n-2){
        return 0;
    } else {
        int min = start;
        for (int i = start + 1; i < n; i++)
        if (arr[i] < arr[min])
            min = i;
        if(min != start)
            swap(arr[min], arr[start]);
        return selectionSort(arr, n, start + 1);
    }
} /* Best: n^2
    Avarage: n^2
    Worst: n^2
*/

int main(){
    int n; 
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int start = 0;
    selectionSort(arr, n, start);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}