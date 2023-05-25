#include "stdio.h"
#include "math.h"
#define max_number 100

typedef struct
{
    int number;
} ArrayNode;

typedef struct 
{
    int size;
    ArrayNode arr[max_number];
} Array;


void init(Array *arr) {
    arr->size = 0;
}

void insert(Array *arr, int number) {
    int s = arr->size;
    ArrayNode node = {number};
    arr->arr[s] = node;
    arr->size++;
}

void check_Triangle_Inequality(Array *arr, int i, int j, int k) {
    if (i < 0) {
        return;
    }
    if (j < 0) {
        check_Triangle_Inequality(arr, i - 1, i - 2, i - 3);
        return;
    }
    if (k < 0) {
        check_Triangle_Inequality(arr, i, j - 1, j - 2);
        return;
    }
    if (arr->arr[i].number + arr->arr[j].number > arr->arr[k].number && arr->arr[k].number + arr->arr[j].number > arr->arr[i].number && arr->arr[i].number + arr->arr[k].number > arr->arr[j].number) {
        printf("%d %d %d \n", arr->arr[i].number, arr->arr[j].number, arr->arr[k].number);
    }
    check_Triangle_Inequality(arr, i, j, k - 1);
}

void display(Array *arr) {
    for (int i = 0; i < arr->size; i++){
        printf("%d, ", arr->arr[i].number);
    }
}

int main() {
    Array f1;
    init(&f1);
    int arr[] = {22, 21, 200, 300, 101, 100, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        insert(&f1, arr[i]);
    }
    // insert(&f1, 21);
    // insert(&f1, 10);
    // insert(&f1, 200);
    // insert(&f1, 100);
    // insert(&f1, 101);
    // insert(&f1, 300);
    // insert(&f1, 22);
    display(&f1);
    printf("\n");
    check_Triangle_Inequality(&f1, size - 1, size - 2, size - 3);
    return 0;
}