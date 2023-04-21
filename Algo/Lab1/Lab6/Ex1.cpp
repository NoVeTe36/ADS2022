#include<bits/stdc++.h>
#include<iostream>

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

struct Node{
    int data;
    Node *left, *right, *parent;
};

Node *newNode(int data){
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


class Tree{
    Node *root;
    int index;
    void createTree(Node *node, int arr){

    }
    void addChild(Node *root, int *arr, int n){
        if (index < n){
            Node *temp = newNode(*arr[index]);
            root->left = temp;
            temp->parent = root;
            index++;
            addChild(root->left, arr, n);
        }
        if (index < n){
            Node *temp = newNode(*arr[index]);
            root->right = temp;
            temp->parent = root;
            index++;
            addChild(root->right, arr, n);
        }
    }
    void recursiveAdd(Node *node, int *index, int *arr){
        node->left = new                            Node;
        node->right = new Node;
        
    }
};

int main(){
    int n;
    cin >> n;
    int count = 0;
    int *arr = new int[n];
    int max = 0;
    int height = ceil(n) + 1;
    int length = pow(2, pushArray(n, count));
    for(int i = 0; i < length; i++){
        for (int j = 0; j < n; j++){
            arr[j] = rand() % 10 + 1;
        } 
        if (arr[i] > max){
            max = arr[i];
        }
        for (int i = n; i < length; i++){
            arr[i] = max + 1;
        }
    }
}