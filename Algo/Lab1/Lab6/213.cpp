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

class Node {
public:
    int data;
    Node* left, *right;
    Node *parent;
    Node(){
        data = 0;
        parent = left = right = NULL;
    }
};

class Tree{
public:
    void createTree(Node *node, int height){
        if (height == 1){
            return;
        }
        else{
            Node *leftNode = new Node;
            node->left = leftNode;
            leftNode->parent = node;
            Node* rightNode = new Node;
            node->right = rightNode;
            rightNode->parent = node;
            createTree(node->left, height - 1);
            createTree(node->right, height - 1);
        }
    }

    void insertLeaf(Node *node, int arr[], int &index, int length){
        if (index >= length){
            return;
        }
        if (node->left == NULL && node->right == NULL){
            node->data = arr[index];
            index++;
            return;
        }
        else{
            insertLeaf(node->left, arr, index, length);
            insertLeaf(node->right, arr, index, length);
        }
    }
    
    void fillTree(Node *root){
        if (!root) {
            return;
        }
        Node *left = root->left;
        Node *right = root->right;
        if (left && right){
            if(left->data < right->data){
                root->data = left->data;
            }
            else{
                root->data = right->data;
            }
        }
        fillTree(root->left);
        fillTree(root->right);
    }

    void displayTree(string prefix, Node* root, bool isRight)
	{
		if (root!=NULL)
		{
			cout << prefix;
			cout << (isRight ? "|--" : "|__");
			cout << root->data<<endl;
			displayTree(prefix + (isRight ? "|   " : "   "), root->right, true);
			displayTree(prefix + (isRight ? "|   " : "   "), root->left, false);
		}
	}

    void subTree(Node *node, int data){
        if (node == NULL){
            return;
        }
        if (node->data == data){
            cout << "Subtree: " << endl;
            displayTree("", node, false);
            return;
        }
        else{
            subTree(node->left, data);
            subTree(node->right, data);
        }
    }
    
    void searching(Node *node, int data){
        if (node == NULL){
            return;
        }
        if (node->data == data){
            cout << "Finding: " << data << endl;
            return;
        }
        else{
            searching(node->left, data);
            searching(node->right, data);
        }
    }

    void deleteNode(Node *node, int data){
        if (node == NULL){
            return;
        }
        if (node->data == data){
            node->data = 0;
            return;
        }
        else{
            deleteNode(node->left, data);
            deleteNode(node->right, data);
        }
    }

};

int main(){
    int n;
    cout << "Enter the number of leaves in array: ";
    cin >> n;
    int count = 0;
    int max = 0;
    int height = ceil(log2(n)) + 1;
    int length = pow(2, pushArray(n, count));
    int *arr = new int[length];
    srand(time(0));
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
    cout << endl;
    cout << "Length: " << length << endl;
    cout << "Height: " << height << endl;
    Tree tree;
    Node *leaves = new Node();
    tree.createTree(leaves, height);
    int index = 0;
    int *p = &index;
    tree.insertLeaf(leaves, arr, *p, length);
    for (int i = 0; i < height; i++){
        tree.fillTree(leaves);
    }
    tree.displayTree("", leaves, false);
    int data;
    cout << "Enter the data to search: ";
    cin >> data;
    tree.searching(leaves, data);
    tree.subTree(leaves, data);
    cout << "Enter the data to delete: ";
    cin >> data;
    tree.deleteNode(leaves, data);
    tree.displayTree("", leaves, false);
    delete[] arr;
    return 0;
}