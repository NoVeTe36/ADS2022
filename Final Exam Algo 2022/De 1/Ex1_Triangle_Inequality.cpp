#include <iostream>

using namespace std;

void check_triangle(int arr[], int i, int j, int k)
{
    // cout << i << " " << j << " " << k << endl;
    if (i < 0)
    {
        return;
    }
    
    if (j < 0)
    {
        check_triangle(arr, i - 1, i - 2, i - 3);
        return;
    }
    
    if (k < 0)
    {
        check_triangle(arr, i, j - 1, j - 2);
        return;
    }
   
    if (arr[i] + arr[j] > arr[k] && arr[k] + arr[j] > arr[i] && arr[i] + arr[k] > arr[j])
    {
        cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
    }
    check_triangle(arr, i, j, k - 1);
}

int main()
{
    int arr[] = {21, 22, 10, 100, 101, 200, 300};
    int n = sizeof(arr) / sizeof(arr[0]);
    check_triangle(arr, n - 1, n - 2, n - 3);
}