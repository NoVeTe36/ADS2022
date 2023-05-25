/*
Pseudo code:
1. Create a new array and init its size
2. Sort the array (normally, the big number will be the divisor)
3. Call the recursive function
    In the recursive function:
    The idea is constructed from the form "a = b * c" where a, b, c are elements of the array
    a = arr[i]
    b = arr[j]
    c = arr[k]
    i = n - 1
    j = n - 2
    k = n - 3
    Base case:
    if (i < 0)
        return
    if (j < 0)
        rec_triplet(arr, i - 1, i - 2, i - 3)
        return
    if (k < 0)
        rec_triplet(arr, i, j - 1, j - 2)
        return
    if (arr[i] / arr[j] == arr[k])
        cout << arr[i] << "=" << arr[j] << "*" << arr[k] << endl
    rec_triplet(arr, i, j, k - 1) 
4. In the recursive function, check if the condition is satisfied
5. If yes, print the triplet
6. If no, call the recursive function again
*/


#include <iostream>

using namespace std;

void swap(int *x, int *y){                                                          // 1
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int n)                                                         // Overall: n^2 + n
{
    for (int i = 0; i < n; i++){                                                    // n^2
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";                                                      // n      
    }
    cout << endl;
}

void rec_triplet(int arr[], int i, int j, int k)                                    // Overall: (n - 1) * (n - 2) * (n - 3)
{
    if (i < 0){
        return;
    }
    
    if (j < 0){
        rec_triplet(arr, i - 1, i - 2, i - 3);                                      // n-2
        return;
    }
    
    if (k < 0){
        rec_triplet(arr, i, j - 1, j - 2);                                          // n-3
        return;
    }
   
    if ((int) arr[i] / arr[j] == arr[k]){                                           // 1
        cout << arr[i] << "=" << arr[j] << "*" << arr[k] << endl;
    }
    rec_triplet(arr, i, j, k - 1);                                                  // n-1
}

int main()
{
    int arr[] = {10, 5, 3, 30, 120, 2, 60, 1440, 90};                               // 1
    int n = sizeof(arr)/sizeof(arr[0]);                                             // 1
    sort(arr, n);                                                                   // 1
    cout << "These triplets are: \n";                                               // 1
    rec_triplet(arr, n - 1, n - 2, n - 3);                                          // 1
}

/*
Complexity: (n - 1)*(n - 2)*(n - 3) + n^2 + n + 5
Time: O(n^3)
*/