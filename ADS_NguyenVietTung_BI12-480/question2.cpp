#include<iostream>
#define max_number 100

using namespace std;

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++){
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
        cout << arr[i] << ", ";
    }
    cout << endl;
}


struct ArrayNode{
    int number;
};

struct Array{
    int size;
    ArrayNode arr[max_number];
};

void init(Array *arr) {
    arr->size = 0;
}

int length(Array *array) {
    return array->size;
}

void insert(Array *arr, int number) {
    int s = arr->size;
    ArrayNode node = {number};
    arr->arr[s] = node;
    arr->size++;
}

void check_Triplets(Array *arr, int i, int j, int k) {
    if (i < 0) {
        return;
    }
    if (j < 0) {
        check_Triplets(arr, i - 1, i - 2, i - 3);
        return;
    }
    if (k < 0) {
        check_Triplets(arr, i, j - 1, j - 2);
        return;
    }
    if ((double) arr->arr[i].number / arr->arr[j].number == arr->arr[k].number) {
        printf("%d = %d * %d \n", arr->arr[i].number, arr->arr[j].number, arr->arr[k].number);
    }
    check_Triplets(arr, i, j, k - 1);
}

void display(Array *arr) {
    for (int i = 0; i < arr->size; i++){
        cout << arr->arr[i].number << ", ";
    }
}

int main() {
    Array f1;
    init(&f1);
    int arr[] = {10, 5, 3, 30, 120, 2, 60, 1440, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        insert(&f1, arr[i]);
    }
    display(&f1);
    cout << endl;
    sort(arr, length(&f1));
    Array f2;
    init(&f2);
    for (int i = 0; i < length(&f1); i++) {
        insert(&f2, arr[i]);
    }
    cout << "\nThose triplets are: " << endl;
    check_Triplets(&f2, length(&f2) - 1, length(&f2) - 2, length(&f2) - 3);
    return 0;
}

/*
Part 2:
To improve the complexity of the program, I already used Sorting and Recursion to reduce the space complexity.
I think here, it's one of the best solutions for this problem because to check the triplets, we need to check all the elements 
in the array. Therefore we have to use iteration (if it's not recursion as i did), i got the code for iterations here:

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

As you can see, the complexity of this code is O(n^3) because we have 3 loops, same big O notation with the recursive, 
just slightly different. But the recursive is better than the iteration because it's more efficient and easier to understand.

- First, with linked list, the memory is allocated dynamically, so it's more flexible than the array. 
  Don't need to specify the size of the array, cause lots of memory is wasted if the array is too big.

- Moreover, combining with the sorting algorithm, small numbers(which are the factors) and big numbers(which are the results) 
will be closer to the point i,j,k as I choose => find much faster. 

For example:
if we have an array: 1000, 50, 45, 78, 69, 39, 47, 40, 96, 25
if we use the iteration, we have to check all the elements in the array, it will take a lot of time.
but if we sort the array, we will have: 78, 39, 40, 45, 47, 96, 69, 25, 50, 1000
through my algorithm, it will immediately find 1000 = 50 * 20 and then move to the next element (no need to search all)


In a nutshell, to my point of view, using Linked List and Recursion is the best solution for this problem.

*/