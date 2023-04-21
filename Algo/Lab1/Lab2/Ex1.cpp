#include<iostream>

using namespace std;

struct Product{
    string name;
    int quantity;
    struct Product *head;
};

struct Costumers {
    int cost[100];
    int top;
};

void init_costumers(Costumers *costumer) {
    costumer->top = -1;
}

int isEmpty(Costumers costumer) {
    if (costumer->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(Costumers costumer) {
    if (costumer->top == 99) {
        return 1;
    }
    return 0;
}

void add_costumers(Costumers *costumer, int n) {
    if (isFull(*costumer)) {
        cout << "The stack is full!" << endl;
    } else {
        costumer->top++;
        costumer->cost[costumer->top].name = n;
    }
}

void remove_costumers(Costumers *costumer) {
    if (isEmpty(*costumer)) {
        cout << "The stack is empty!" << endl;
    } else {
        costumer->top--;
    }
}



int main(){
    int n;
    cout << "Enter the number of costumers: ";
    cin >> n;
}