#include<iostream>
#define MAX 100000

using namespace std;

struct Node {
    int data;
    Node *prev, *next;
};

struct Node *head, *tail = NULL;

struct List {
    int size;
    Node *pHead;
    Node *pTail;
};

void init(List &l) {
    l.size = 0;
    l.pHead = l.pTail = NULL;
}

void initNode(Node *a){
    cin >> a->data;
    a->prev = a->next = NULL;
}

void insert(Node *a, List *list) {
    if (list->size == 0) {
        list->pHead = a;
        list->pTail = a;
        list->size++; 
    } else {
        list->pTail->next = a;
        a->prev = list->pTail;
        list->pTail = a;
        list->size++;
    }
}

void Sort(List * list) {
    Node *p = list->pHead;
    Node *q = list->pTail;
    bool swap_approved = false;
    while (p->next != NULL) {
        if (p->data > p->next->data) {
            swap(p->data, p->next->data);
            swap_approved = true;
        }
        p = p->next;
    }
    if (swap_approved == false) {
        return;
    }
    while (q->prev != NULL) {
        if (q->data < q->prev->data) {
            swap(q->data, q->prev->data);
            swap_approved = true;
        }
        q = q->prev;
    }
}

int main() {
    List list;
    init(list);
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "\nInsert elements: ";
    for (int i = 0; i < n; i++) {
        Node *a = new Node;
        initNode(a);
        insert(a, &list);
    }
    cout << "\nAfter being sorted the array is: ";
    Sort(&list);
    for (int i = 0; i < n; i++) {
        cout << list.pHead->data << " ";
        list.pHead = list.pHead->next;
    }
    return 0;
}