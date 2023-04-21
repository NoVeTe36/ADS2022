#include<iostream>

using namespace std;

struct Item{
    string name;
    int quantity;
    Item *next;
};

struct Stock{
    int size = 0;
    Stock* head = NULL;
};

void init(Stock *s){
    s->size = 0;
    s->head = NULL;
}

void init(Item *i){
    Item *i = new Item();
    i->name = name;
    i->quantity = quantity;
    return i;
}



int main(){

}