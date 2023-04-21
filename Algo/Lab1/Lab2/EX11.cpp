#include<iostream>
#include<math.h>

using namespace std;

struct Product{
    string name_of_product;
    int quantity;
};

void ProductInfo(string name, int quantity) {
    product->name_of_product = name_of_product;
    product->quantity = quantity;
}

void printProduct(Product product) {
    cout << "Product name: " << product.name_of_product << endl;
    cout << "Product quantity: " << product.quantity << endl;
}

struct Costumers {
    string cost[100];
    int top, end;
};

void init_costumers() {
    costumer.top = 0;
    costumer.end = 0;
}

int isEmpty(Costumers costumer) {
    if (costumer.top == -1) {
        return 1;
    }
    return 0;
}

int isFull(Costumers costumer) {
    if (costumer.top == 99) {
        return 1;
    }
    return 0;
}

int length(Costumers *costumer) {
    return abs(costumer.top - costumer.end);
}

void add_costumers(Costumers *costumer, string new_costumers) {
    if (isFull(costumer)) {
        cout << "The stack is full!" << endl;
    }
    if (isEmpty(costumer)) {
        costumer->top++;
        costumer->cost[costumer->top] = new_costumers;
    } else {
        int index = costumer->end;
        costumer->cost[index] = new_costumers;
    }
    costumer->end++;
    return 1;
}

void remove_costumers(Costumers *costumer) {
    if (isEmpty(costumer)) {
        cout << "The stack is empty!" << endl;
    } else {
        if (length(costumer) >= 1) {
            for (int i = 0; i < length(costumer); i++) {
                costumer->cost[i] = costumer->cost[i + 1];
            }
        }
        costumer->end--;
    }
}

int main(){
    ProductInfo("Milk", 10);
    printProduct(Product);
}
