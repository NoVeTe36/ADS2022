#include<iostream>

using namespace std;

struct Items{
    string name;
    int quantity;
    Items *next;
};

struct Stock{
    int size;
    Items *head;
};

void init(Stock *s){
    s->size = 0;
    s->head = NULL;
}

int isEmpty(Stock *s){
    return s->size == 0;
}

Items *init(Items *i){
    cout << "\nEnter name of product: ";
    cin >> i->name;
    cout << "\nEnter quantity of product: ";
    cin >> i->quantity;
    i->next = NULL;
} 

void insert(Stock *s, Items *i){
    if(isEmpty(s)){
        s->head = i;
    }else{
        Items *temp = s->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = i;
    }
    s->size++;
}

void display(Stock *s){
    Items *temp = s->head;
    while(temp != NULL){
        cout << "Product " << temp->name << " has " << temp->quantity << endl;
        temp = temp->next;
    }
}

struct Customers{
    string name;
    int value;
    Customers *next;
};


struct Queues{
    int size;
    Customers *head, *tail;
};

void init(Queues *q){
    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
}


int isEmpty(Queues *q){
    return q->size == 0;
}

void enqueue(Queues *q, Customers *c){
    if(isEmpty(q)){
        q->head = c;
        q->tail = c;
    }else{
        q->tail->next = c;
        q->tail = c;
    }
    q->size++;
}

void display(Queues *q){
    Customers *temp = q->head;
    while(temp != NULL){
        cout << "Customer " << temp->name << endl;
        temp = temp->next;
    }
}

void checkout(Queues *q, Customers *c, Stock *s){
    if(isEmpty(q)){
        cout << "No customers in queue" << endl;
    }else{
        Customers *temp = q->head;
        string Product_name;
        cout << "Enter (exactly) the name of the product want to buy: ";
        cin >> Product_name;
        while(temp != NULL){
            if(Product_name == s->name){
                cout << "Enter the number want to buy: ";
                cin >> temp->value;
                cout << "Customer " << temp->name << " has " << temp->value << " of " << Product_name << " in their cart" << endl;
                cout << "Do this customer want to buy more product? (y/n) ";
                char choice;
                cin >> choice;
                if(choice == 'y'){
                    checkout(q, c, i);
                }
                else {
                    break;
                }
            }
            else{
                cout << "No such product in the cart" << endl;
                cout << "Do this customer want to buy more product? (y/n) ";
                char choice;
                cin >> choice;
                if(choice == 'y'){
                    checkout(q, c, i);
                }
                else {
                    break;
                }
            }
        return;
        }
    }
}

int main(){
    Stock *milk = new Stock();
    init(milk);
    Stock *s = new Stock();
    init(s);
    cout << "Enter number of products: ";
    int n;
    cin >> n;
    for(int j = 0; j < n; j++){
        Items *i = new Items();
        init(i);
        insert(s, i);
    }
    display(s);
    Queues *q = new Queues();
    init(q);
    cout << "Enter number of customers: ";
    int m;
    cin >> m;
    for(int j = 0; j < m; j++){
        Customers *c = new Customers();
        cout << "\nEnter name of customer: ";
        cin >> c->name;
        c->next = NULL;
        enqueue(q, c);
        checkout(q, c, s->head);
    }
    display(q);
}