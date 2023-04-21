#include <iostream>
#include <math.h>
#define count 8
using namespace std;
class Node
{
public:
	int data;
	Node* left;
	Node* right;
	Node* up;
	Node()
	{
		data = 0;
		left = right = up = NULL;
	}
};

class Tree
{
	int choice;
	int check(int choice)
	{
		if (choice > 0)
			return choice;
		else
		{
			cout << "Wrong input!";
			return -1;
		}
	}
public:
	void create_tree(Node* root, int level)
	{
		if (level == 0)
			return;
		Node* leftnode = new Node();
		root->left = leftnode;
		leftnode->up = root;
		Node* rightnode = new Node();
		root->right = rightnode;
		rightnode->up = root;
		create_tree(root->left, level - 1);
		create_tree(root->right, level - 1);
	}

	void insertLeaf(Node* root)
	{
		if (!root->left && !root->right)
		{
			cout << "Insert data: ";
			cin >> root->data;
			return;
		}
		insertLeaf(root->left);
		insertLeaf(root->right);
	}

	void disp_tree(string prefix, Node* root, bool isRight)
	{
		if (root!=NULL)
		{
			cout << prefix;
			cout << (isRight ? "|--" : "|__");
			cout << root->data<<endl;
			disp_tree(prefix + (isRight ? "|   " : "   "), root->right, true);
			disp_tree(prefix + (isRight ? "|   " : "   "), root->left, false);
		}
	}

	void fill_tree(Node* root)
	{
		if (!root)
			return;
		Node* left = root->left;
		Node* right = root->right;
		if (left && right)
		{
			if (left->data > right->data)
				root->data = root->right->data;
			else
				root->data = root->left->data;
		}
		fill_tree(root->left);
		fill_tree(root->right);
	}


};

int main()
{
	int choice;
	Tree tree;
	Node *root = new Node();
	int n;
	cout << "How many numbers you want to sort? ";
	cin >> n;
	int level = (log2(n)) + 1;
	tree.create_tree(root, level);
	tree.insertLeaf(root);
	for(int i=0; i<level;i++)
		tree.fill_tree(root);
	cout << "Tree:" << endl;
	tree.disp_tree("",root,false);
}