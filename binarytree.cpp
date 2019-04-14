//*******************************************************
//
// An T. Vo
// CS 302 - 1002, November 6th 2018
// Assignment #6
//
//*******************************************************

#include "binarytree.h"

// constructor btree will initialize the root
btree::btree()
{
	root = NULL;
}

// destructor ~btree will deallocate the root
btree::~btree()
{
	destroy_tree();
}

// destroy_tree() will deallocate the root with recursion
void btree::destroy_tree()
{
	destroy_tree(root);
}

// destroy_tree(node *leaf) will deallocate the root with recursion 
void btree::destroy_tree(node *leaf)
{
	if(leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
	else
		return;
}

//***********************************************************************
// PRINT
// inorder_print() will print frequencies and letters in order
void btree::inorder_print()
{
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf)
{
	if (leaf != NULL)
	{
		inorder_print(leaf->left);
		cout << leaf->letter << " " << leaf->frequency << endl;
		inorder_print(leaf->right);
	}
	else
		return;	
}

void btree::postorder_print()
{
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf)
{
	if (leaf != NULL)
	{
		postorder_print(leaf->left);
		postorder_print(leaf->right);
		cout << leaf->letter << " " << leaf->frequency << endl;
	}
	else
		return;		
}

void btree::preorder_print()
{
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf)
{
	if (leaf != NULL)
	{
		cout << leaf->letter << " " << leaf->frequency << endl;
		preorder_print(leaf->left);
		preorder_print(leaf->right);
	}
	else
		return;		
}

//***********************************************************************
// INSERT

// insert(int frequency) HARD CODING, getting the space 
void btree::insert_space(int frequency)
{
	root = new node;
	root->frequency = frequency;
	root->letter = ' ';
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	root->successor = NULL;
}
void btree::insert(int frequency, char letter)
{
	if (root != NULL)
	{
		insert(frequency, letter, root);
	}
	else
	{
		root = new node;
		root->frequency = frequency;
		root->letter = letter;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		root->successor = NULL;
	}
}

void btree::insert(int frequency, char letter, node *leaf)
{
	if (frequency < leaf->frequency)
	{
		if (leaf->left != NULL)
			insert(frequency, letter, leaf->left);
		else
		{
			leaf->left = new node;
			leaf->left->frequency = frequency;
			leaf->left->letter = letter;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->parent = NULL;
			leaf->left->successor = NULL;
		}
	}
	else if (frequency >= leaf->frequency)
	{
		if (leaf->right != NULL)
			insert(frequency, letter, leaf->right);
		else
		{
			leaf->right = new node;
			leaf->right->frequency = frequency;
			leaf->right->letter = letter;
			leaf->right->left = NULL;
			leaf->right->right = NULL;
			leaf->right->parent = NULL;
			leaf->right->successor = NULL;
		}
	}
}

node *btree::search(int frequency, char letter)
{
	return search(frequency, letter, root);
}

node *btree::search(int frequency, char letter, node *leaf)
{
	if (leaf != NULL)
	{
		if (frequency == leaf->frequency && letter == leaf->letter)
			return leaf;
	}
	if (frequency < leaf->frequency)
		return (frequency, letter, leaf->left);
	else
		return (frequency, letter, leaf->right);
}

//***********************************************************
// copy and overload = for the tree
/*
void btree::copyTree(const btree &otherTree)
{

	btree *current;
	
	if(otherTree.root == NULL)
		return;
	else
	{
		root->frequency = otherTree.root->frequency;
		root->letter = otherTree.root->letter;
		root->left = NULL;
		root->right = NULL;
		root->parent = NULL;
		root->successor = NULL;
		while (otherTree.root->left != NULL)
			copyNode(root->left, otherTree.root->left);
		while (otherTree.root->right !=NULL)
			copyNode(root->right, otherTree.root->right);
	}
}

void btree::copyNode(const node *leaf)
{
	if(leaf == NULL)
		return;
	else
	{

	}
}

const btree& btree::operator =(const btree &otherTree)
{
	// avoid self-copy
	if(this != otherTree)
		copyTree(otherTree);
	return *this;
}
*/


/*
struct node
{
	int frequency;
	char letter;
	node *left;
	node *right;
	node *parent; 		// Dr. Larmore's instruction
	node *successor; 	// Dr. Larmore's instruction
};

class btree
{
public:
	btree();
	~btree();

	void insert(int frequency, char letter);
	node *search(int frequency, char letter);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node *leaf); 							// deallocating with recursion
	void insert(int frequency, char letter, node *leaf); 	// inserting with recursion
	node *search(int frequency, char letter, node *leaf); 	// searching with recursion
	void inorder_print(node *leaf); 						// printing with recursion
	void postorder_print(node *leaf); 						// printing with recursion
	void preorder_print(node *leaf);						// printing with recursion

	node *root;
};
*/