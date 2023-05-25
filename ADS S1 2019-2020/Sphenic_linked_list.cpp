// Check sphenic using linked list
//
// 1. Create a linked list
// 2. Check if the number is prime
// 3. If it is prime, add it to the linked list
// 4. Check if the number is sphenic
// 5. If it is sphenic, add it to the linked list
// 6. Print the linked list
//
// */
//
#include <iostream>
#include <math.h>

using namespace std;

struct node {
    int data;
    node *next;
};

class linkedList {
    private:
        node *head, *tail;
    public:
        linkedList() {
            head = NULL;
            tail = NULL;
        }
        void createNode(int value) {
            node *temp = new node;
            temp->data = value;
            temp->next = NULL;
            if (head == NULL) {
                head = temp;
                tail = temp;
                temp = NULL;
            } else {
                tail->next = temp;
                tail = temp;
            }
        }
        void display() {
            node *temp = new node;
            temp = head;
            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

bool isPrime(int a) {
    int count = 0;
    if (a == 1 || a == 0) {
        return 0;
    }
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            count++;
        }
    }
    if (count == 0) {
        return true;
    }
    if (count != 0) {
        return false;
    }
}

int checkSphenic(int n) {
    int count = 0;
    int plus = 0;
    int arr[50000] = {};
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            arr[plus] = i;
            plus++;
        }
    }
    if (plus == 8) {
        for(int plus = 0; plus <= 5; plus++) {
            if (isPrime(arr[plus]) == true ) {
                count++;
            } 
        }
        if (count == 3) {
            return 1;
        }
    }
}

int main() {
    int n = 0;
    int overall = 0;
    linkedList list;
    cout << "Enter a number: ";
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (checkSphenic(i) == 1) {
            list.createNode(i);
        }
    }
    list.display();
    return 0;
}