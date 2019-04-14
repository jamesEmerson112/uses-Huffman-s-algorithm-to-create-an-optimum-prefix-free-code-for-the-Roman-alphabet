//*******************************************************
//
// An T. Vo
// CS 302 - 1002, November 6th 2018
// Assignment #6
//
//*******************************************************

/* Why a binary tree?
 * To store the information and data
 * Insert is used to insert a node into a tree
 * destroy_tree is used to deallocate the tree
 */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>

using namespace std;

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

	void insert_space(int frequency);
	void insert(int frequency, char letter);
	node *search(int frequency, char letter);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

//	const btree& operator = (const btree &othertree);

private:
	void destroy_tree(node *leaf); 							// deallocating with recursion
	void insert(int frequency, char letter, node *leaf); 	// inserting with recursion
	node *search(int frequency, char letter, node *leaf); 	// searching with recursion
	void inorder_print(node *leaf); 						// printing with recursion
	void postorder_print(node *leaf); 						// printing with recursion
	void preorder_print(node *leaf);						// printing with recursion

	node *root;
//	void copyTree(const btree &othertree);
//	void copyNode(node *leaf, const node *leaf);
};

#endif