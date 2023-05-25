#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int passengers;
    char name[20];
    struct Car *next;
} Car;

typedef struct {
    int size;
    int max_size;
    Car *pHead;
} Train;

void initTrain(Train *train, int N) {
    train->size = 0;
    train->max_size = N;
    train->pHead = NULL; 
    printf("Empty train created with %d cars\n", N);
}

int isEmpty(Train *train) {
    return train->size == 0;
}

Car *getCar(int passengers, char *name) {
    Car *pCar = malloc(sizeof(Car));
    pCar->passengers = passengers;
    strcpy(pCar->name, name);
    return pCar;
}


void addFirst(Train *train, Car *newCar) {
    if (isEmpty(train) == 1) {
        train->size++;
        train->pHead = newCar;
    }
}

void insert(Train *train, Car *newCar, Car *oldCar) {
    if(train->size < train->max_size) {
        newCar->next = oldCar->next;
        oldCar->next = newCar;
        train->size++;
    }
}

void remove_zero(Train *train, Car *p){
    if(isEmpty(train) == 0){
        Car *o = p->next;
        if(o->passengers == 0){
            printf("\nRemoved: %c",p->name);
            p->next = o->next;
            free(o);
            train->size--;
        }
    }
}

void display(Train *train) {
    Car *p = train->pHead;
    int count = 0;
    while (train->size < train->max_size && count < train->size) {
        remove_zero(train, p);
        printf("\n%d - %s", p->passengers, p->name);
        p = p->next;
        count++;
    }
}

int length(Train *train) {
    return train->size;
}

int main() {
    Train Train1;
    initTrain(&Train1, 8);
    Car *c1 = getCar(8, "A");
    Car *c2 = getCar(0, "B");
    Car *c3 = getCar(5, "C");
    Car *c4 = getCar(2, "");
    Car *c5 = getCar(1, "E");
    addFirst(&Train1, c1);
    insert(&Train1, c2, c1);
    insert(&Train1, c3, c2);
    insert(&Train1, c4, c3);
    printf("Length of train is: %d", length(&Train1));
    display(&Train1);
    return 0;
}