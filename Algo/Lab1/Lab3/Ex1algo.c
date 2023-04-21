#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node {
    int no;
    char name;
    struct Node *next;
} Car;

int length(Train *T){
    return T->size;
}

typedef struct List {
    int size;
    Train* head = NULL;
} Train;

void initTrain(Train* T) {
    T->size = 0;
    T->head = NULL;
}

Car* initCar(char _name, int _no) {
    Car* ptr = (Car*)malloc(sizeof(*ptr));
    ptr->name = _name;
    ptr->no = _no;
    return ptr;
}

void addFirst(Train* T, Car* new) {
    T->head = new;
    new->next = NULL;
    T->size++;
}

void insert(Train* T, Car* new) {
    new->next = T->head;
    T->head = new;
    T->size++;
}

void remove_car(char _name, Train* T) {
    Car* t = T->head;
    if(t->name == _name){
        T->head = t->next;
        free(t);
        size--;
        return;
    }
    Car* t2 = t;
    t = t->next;
    for (int i = 2; i<=length(T); i++){
        if(t->name == _name){
            t2->next = t->next;
            size--;
            free(t);
            return;
        }
        t2 = t;
        t = t->next;
    }
    printf("No such car!\n");
    return;
}

void remove_guest(char _name; int _no, Train* T) {
    Car* t = T-> head;
    if (t->name == _name) {
        t->no -= _no;
        if (t->no == 0){
            remove_car(_name, T);
            return;
        }
    }
    printf("No such car!\n");
}

void add_guest(char _name, int _no, Train* T) {
    Car* t = T-> head;
    for (int i = 0; i < length(T); i++) {
        if (t->name == _name) {
            t->no += _no;
            return;
        }
        t = t->next;
    }
    printf("No such car!\n");
}

void display(Train* T){
    Car* t = T->head;
    for (int i = 0; i < length(T); i++) {
        printf("[%c : %i] - ", t->name, t->no);
        t = t->next;
    }
}

int main(){
    Train T;
    initTrain(&T);
    Car* new = initCar('a', 8);
    addFirst(new, &T);
    display(&T);    
}





