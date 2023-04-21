#include <bits/stdc++.h>
#include<iostream>
#include<math.h>
#include<time.h>

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
   Node *parent;
};

struct Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    node->parent = NULL;
    return node;
}

void insertNewNode(Node** root, int data) {
    Node* node = newNode(data);
    Node* ptr;
    if (*root == NULL) {
        *root = node;
    }
    else {
        ptr = *root;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}

void printLinkedList(Node* root) {
    while (root != NULL) {
        cout << root->data << " -> ";
        root = root->next;
    }
    cout << "NULL" << endl;
}

Node* createLinkedList(int arr[], int n) {
    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        insertNewNode(&root, arr[i]);
    }
    return root;
}



void displayTree(Node* ptr, int height, int length) {
    Node *tree[height][length];
    for (int i = 0; i < height; i++){
        for (int j = 0; j < length; j++){
            tree[i][j] = NULL;
        }
    }
    for (int i = 0; i < length; i++){
        tree[0][i] = ptr;
        ptr = ptr->next;
    }
    for (int i = 1; i < height; i++){
        for (int j = 0; j < length; j += 2){
            if (tree[i-1][j] != NULL && tree[i-1][j+1] != NULL){
                if (tree[i-1][j]->data < tree[i-1][j+1]->data){
                    tree[i][j] = tree[i-1][j];
                    tree[i][j]->parent = tree[i-1][j+1];
                }
                else{
                    tree[i][j] = tree[i-1][j+1];
                    tree[i][j]->parent = tree[i-1][j];
                }
            }
        }
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < length; j++){
            if (tree[i][j] != NULL){
                cout << tree[i][j]->data << " ";
            }
        }
        cout << endl;
    }
}

int main(){
    int n;
    cin >> n;
    int count = 0;
    int max = 0;
    int length = pow(2, pushArray(n, count));
    int arr[length];
    srand(time(0));
    for(int i=0; i < length; i++){
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
    Node *root = createLinkedList(arr, length);
    printLinkedList(root);
    int height = ceil(log2(length)) + 1;
    cout << "Height of tree: " << height << endl;
    cout << "Length of tree: " << length << endl;
    displayTree(root, height, length);
    return 0;
}
