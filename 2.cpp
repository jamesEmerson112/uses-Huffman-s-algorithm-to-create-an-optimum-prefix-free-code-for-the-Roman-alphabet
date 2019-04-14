//*******************************************************
//
// An T. Vo
// CS 302 - 1002, November 6th 2018
// Assignment #6
//
//*******************************************************

/* Write a C++ program which uses Huffman's algorithm to create an optimum prefix-free code for the
 * the Roman alphabet, together with ta symbol for space, using the frequencies of letters used in
 * English. Since I want everyone's code to be the same, you must use the list of
 * frequencies given in the file.
 */

/*
this time.
1. Create an array of class binary tree
	a. where each element is a small binary tree of the given data
2. push each of the element belonging to the array to a priority queue
3. Then use the priority queue to create an entire binary tree of the 
Huffman operation
*/

#include <iostream>
#include <fstream>
#include <queue>
#include "binarytree.h"

using namespace std;

const int ORIGINAL_NUMBER_OF_NODES = 27;

void readInput();

int main()
{
	cout << "hello" << endl;

	readInput();

	system("pause");
	return 0;
}

// readInput() will read all characters and print them out
void readInput()
{
	// variable to hold input characters
	char letter;
	int frequencies;

	// variable for the ifstream
	ifstream infile;

	// declaring variables
	btree test[ORIGINAL_NUMBER_OF_NODES]; 			// TEST tree
	priority_queue<btree> queueOfSmallTrees;
	int count = 0;


	// open file
	infile.open("frequencies.txt");

	// check if the file is correct
	if (!infile)
	{
		cout << "Wrong input file" << endl; 			// LARMORE
		system("pause");
		return;
	}

	infile >> frequencies;
	test[count].insert_space(frequencies);
	// test[count].inorder_print();
	++count;
	// cout << count << endl;

	while (!infile.eof())
	{
		infile >> letter >> frequencies;
		test[count].insert(frequencies, letter);
		++count;
	}

	for (int i = 0; i < ORIGINAL_NUMBER_OF_NODES; ++i)
	{
		test[i].inorder_print();
		cout << "\n";
	}

	/* after breaking the data into small trees
	the next step is:
	1. push all items into a priority queue
	2. creating binary Tree #1 and binary #2 that take data
	(the two smallest trees) from the priority
	queue 
	3. combine them together to create the same binary tree
	4. push it into the priority queue
	5. re-doing until the size of the queue = 1.
	*/

/*	
	for (int i = 0; i < ORIGINAL_NUMBER_OF_NODES; ++i)
	{
		queueOfSmallTrees.push(test[i]);
	}
*/
	//btree *h1;

	//h1 = queueOfSmallTrees.top();

	//h1.inorder_print();

	infile.close();
}