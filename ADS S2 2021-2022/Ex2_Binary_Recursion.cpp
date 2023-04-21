#include<bits/stdc++.h>
using namespace std;

int find_min(int arr[], int left, int end_right, int &min_idx){
    if (left > end_right){
        return 0;
    } else {
        if (arr[min_idx] > arr[left]){
            min_idx = left;
        }
        return find_min(arr, left + 1, end_right, min_idx);
    }
} //Complexity: T(n) = n, with n is number of elements in array

int find_max(int arr[], int right, int end_left, int &max_idx){
    if (right < end_left){
        return 0;
    } else {
        if (arr[max_idx] < arr[right]){
            max_idx = right;
        }
        return find_max(arr, right - 1, end_left, max_idx);
    }
} //Complexity: T(n) = n, with n is number of elements in array

int selection_sort(int arr[], int n, int start){
    if (start > n/2){
        return 0;
    } else {
        int min_idx = start;
        find_min(arr, min_idx + 1, n - 1, min_idx);
        swap(arr[start], arr[min_idx]);
        int max_idx = n - 1 - start;
        find_max(arr, max_idx - 1, 0, max_idx);
        swap(arr[n - start - 1], arr[max_idx]);
        selection_sort(arr, n, start + 1);
    }
} /*    We put the minimum value to the beginning of the array, and also put the maximum value to the ending of the array 
        in 1 loop of recursion function. So, running time in each loop is: n + n = 2n
        Moreover, the function stops when the value is in half of array, so we must run n/2 recursion loops.
        => T(n) = n/2 * 2n = n^2
        Best case: Omega(n^2), when the array has already in ascending order
        Avarage: Theta(n^2)
        Worst case: O(n^2)
*/

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    selection_sort(arr, n, 0);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}/*     Best case: Omega(n^2), when the array has already in ascending order
        Avarage: Theta(n^2)
        Worst case: O(n^2)
*/
