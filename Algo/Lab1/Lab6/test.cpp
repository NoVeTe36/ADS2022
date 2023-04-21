#include<iostream>
#include<math.h>

using namespace std;

int pushArray(int n, int count){
    if (n <= 2){
        return (count + 1);
    }
    else{
        if (n % 2 == 0){
            return pushArray(n/2, count + 1);
        }
        else{
            return pushArray(round(n/2 + 0.5), count + 1);
        }
    }
}

struct Node {
    int data;
    Node* next;
};

Node *init(int data){
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

void insert(Node *node, int data) {
    Node *node = init(data);
    Node *ptr;
    if(*root == NULL){
        *root = node;
    }
    else{
        ptr = *root;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}

void print(Node *root){
    Node *ptr = root;
    while(ptr != NULL){
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main(){
    int n;
    cin >> n;
    int count = 0;
    int max = 0;
    int length = pow(2, pushArray(n, count));
    int arr[length];
    for(int i = 0; i < length; i++){
        for (int j = 0; j < n; j++){
            arr[i] = rand() % 10;
        }
        if (arr[i] > max){
            max = arr[i];
        }
        for (int i = n; i < length; i++){
            arr[i] = max + 1;
        }
    }
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
}