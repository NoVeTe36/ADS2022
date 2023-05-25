#include "stdio.h"
#include "math.h"
#define max_exponent 100

typedef struct
{
    double coefficient;
    int exponent;
} Terms;

typedef struct 
{
    int size;
    Terms arr[max_exponent];
} Polynomial;


void init(Polynomial *poly) {
    poly->size = 0;
}

void insert(Polynomial *poly, double coefficient, int exponent) {
    int s = poly->size;
    for (int i = 0; i < s; i++){
        if (poly->arr[i].exponent == exponent){
            poly->arr[i].coefficient += coefficient;
            return;
        }
    }
    while (poly->arr[s-1].exponent > exponent && s > 0){
        poly->arr[s] = poly->arr[s - 1];
        s--;
    }
    Terms term = {coefficient, exponent};
    poly->arr[s] = term;
    poly->size++;
}

void display(Polynomial *poly) {
    for (int i = 0; i < poly->size; i++){
        printf("+ %.1fx^%d ", poly->arr[i].coefficient, poly->arr[i].exponent);
    }
}

void del(Polynomial *poly, int exponent) {
    int s = poly->size;
    for (int i = 1; i <= s; i++){
        if (poly->arr[i].exponent >= exponent){
            poly->arr[i-1] = poly->arr[i];
        }
    }
    poly->size--;
}

double cal(Polynomial *poly, double x) {
    double calculate;
    for (int i = 0; i < poly->size; i++)
        calculate += poly->arr[i].coefficient * pow(x, poly->arr[i].exponent);
    return calculate;    
}

int main() {
    Polynomial f1;
    init(&f1);
    insert(&f1, 5, 2);
    insert(&f1, 2, 3);
    insert(&f1, 1, 2);
    insert(&f1, 3, 0);
    display(&f1);
    printf("\nf(%.5f) = %.5f\n", 3.0, cal(&f1, 3.0));
    return 0;
}