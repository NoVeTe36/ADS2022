#include <iostream>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                swap(&arr[j], &arr[i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rec_triplet(int arr[], int i, int j, int k)
{
    // cout << i << " " << j << " " << k << endl;
    if (i < 0)
    {
        return;
    }
    
    if (j < 0)
    {
        rec_triplet(arr, i - 1, i - 2, i - 3);
        return;
    }
    
    if (k < 0)
    {
        rec_triplet(arr, i, j - 1, j - 2);
        return;
    }
   
    if ((double) arr[i] / arr[j] == arr[k])
    {
        cout << arr[i] << "=" << arr[j] << "*" << arr[k] << endl;
    }
    rec_triplet(arr, i, j, k - 1);
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, n);
    rec_triplet(arr, n - 1, n - 2, n - 3);
}