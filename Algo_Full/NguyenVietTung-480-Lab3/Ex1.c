#include <stdio.h>
#include <stdlib.h>

typedef struct Customer{
    int Sand;
    int Mud;
    int Dirt;
    struct Customer* next;
} Customer;

typedef struct Queue{
    int size;
    Customer* front;
} Queue;

Customer* initCustomer(int numOfSand, int numOfMud, int numOfDirt){
    Customer* p = (Customer*) malloc(sizeof (*p));
    p->Sand = numOfSand;
    p->Mud = numOfMud;
    p->Dirt = numOfDirt;
    return p;
}

void initQueue(Queue* q){
    q->size = 0;
    q->front = NULL;
}

int length(Queue* Q){
    return Q->size;
}

void AddFirst(Customer* new, Queue* q){
    q->front = new;
    new->next = NULL;
    q->size++;
}

void Add(Customer* new, Queue* q){
    new->next = q->front;
    q->front = new;
    q->size++;
}

void Reduce(Customer* new, int numOfSand, int numOfDirt, int numOfMud){
    new->Sand -= numOfSand;
    new->Mud -= numOfMud;
    new->Dirt -= numOfDirt;
}

void RemoveInitial(Queue *q){
    Customer* t = q->front;
    for (int i = 1; i <= (q->size-1); i++){
        t = t->next;
    }
    q->size--;
}

Customer* getFront(Queue* q){
    return q->front;
}

void checkout(Queue* q, Customer* new, int *numOfSand, int *numOfDirt, int *numOfMud){
loop_point:
    if ( new->Sand > *numOfSand ) {
        printf("Not enough Sand!\n");
        printf("Do you want to remove %i Sand? Y/N: ", (new->Sand - *numOfSand));
        char select;
        scanf("%c", &select);
        if (select == 'Y'){
            Reduce(new, (new->Sand - *numOfSand), 0, 0);
        }
        else {
            goto loop_point;
        }
    }
    if (new->Dirt > *numOfDirt){
        printf("Not enough Dirt!\n");
        printf("Do you want to remove %i Sand? Y/N: ", (new->Dirt - *numOfDirt));
        char select;
        scanf("%c", &select);
        if (select == 'Y'){
            Reduce(new, 0, (new->Dirt - *numOfDirt), 0);
        }
        else {
            goto loop_point;
        }
    }
    if (new->Mud > *numOfMud){
        printf("Not enough Mud!\n");
        printf("Do you want to remove %i Mud? Y/N: ", (new->Mud - *numOfMud));
        char select;
        scanf("%c", &select);
        if (select == 'Y'){
            Reduce(new, 0, 0, (new->Mud - *numOfMud));
        }
        else{
            goto loop_point;
        }
    }
    printf("You are currently having %i Sand, %i Dirt, %i Mud.\nDo you want to check out? Y/N: ", new->Sand, new->Dirt, new->Mud);

    char select;
    scanf("%i", &select);
    if (select == 'Y'){
        RemoveInitial(q);
    }
    else {
        int a;
        printf("Choose the number of Mud you want to buy more: ");
        scanf("%i", &a);
        new->Mud = a;
        printf("Choose the number of Sand you want to buy more: ");
        scanf("%i", &a);
        new->Sand = a;
        printf("Choose the number of Dirt you want to buy more: ");
        scanf("%i", &a);
        new->Dirt = a;
        goto loop_point;
    }
    *numOfSand -= new->Sand;
    *numOfDirt -= new->Dirt;
    *numOfMud -= new->Mud;
    RemoveInitial(q);
    return;
}

int main(){
    int sand_in_storage;
    int dirt_in_storage;
    int mud_in_storage;
    printf("How many Mud in stock: ");
    scanf("%i", &mud_in_storage);
    printf("How many Sand in stock: ");
    scanf("%i", &sand_in_storage);
    printf("How many Dirt in stock: ");
    scanf("%i", &dirt_in_storage);
    Queue q;
    initQueue(&q);
/*
    int numOfCustomer; 
    printf("How many customer: ");
    scanf("%i", &numOfCustomer);
    for (int i = 0; i < numOfCustomer; i++){
        int numOfSand;
        int numOfDirt;
        int numOfMud;
        printf("How many Sand does customer %i want: ", i+1);
        scanf("%i", &numOfSand);
        printf("How many Dirt does customer %i want: ", i+1);
        scanf("%i", &numOfDirt);
        printf("How many Mud does customer %i want: ", i+1);
        scanf("%i", &numOfMud);
        Customer* new = initCustomer(numOfSand, numOfDirt, numOfMud);
        if (length(&q) == 0){
            AddFirst(new, &q);
        }
        else {
            Add(new, &q);
        }
    }
    Customer* new = getFront(&q);
    checkout(&q, new, &sand_in_storage, &dirt_in_storage, &mud_in_storage);
    return 0;
*/
loop_point2:
    printf("What do you want to do?\n(1) Add Customer\n(2) Check-out for first Customer\nChoose: ");
    char select;
    scanf("%i", &select);
    if (select == 'Y'){
        int mud, sand, dirt;
        printf("Number of Mud you want to buy: ");
        scanf("%i", &mud);
        printf("Number of Sand you want to buy: ");
        scanf("%i", &sand);
        printf("Number of Dirt you want to buy: ");
        scanf("%i", &dirt);
        Customer* new = initCustomer(mud, sand, dirt);
        if (length(&q) == 0){
            AddFirst(new, &q);
        }
        else{
            Add(new, &q);
        }
        goto loop_point2;
    }
    else{
        checkout(&q, getFront(&q), &sand_in_storage, &dirt_in_storage, &mud_in_storage);
        printf("There are %i Sand, %i Dirt, %i Mud remaining in the storage. \n", &sand_in_storage, &dirt_in_storage, &mud_in_storage);
        goto loop_point2;
    }
    return 0;
}
