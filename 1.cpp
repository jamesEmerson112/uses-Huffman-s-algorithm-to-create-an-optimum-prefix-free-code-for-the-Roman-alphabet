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
1. Create the tree list
2. Create a priority queue to en take the tree
3. 
*/

#include <iostream>
#include <fstream>
#include "binarytree.h"

using namespace std;

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

	// declaring a TEST tree
	btree test;

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
	test.insert_space(frequencies);
	test.inorder_print();

	while (!infile.eof())
	{
		infile >> letter >> frequencies;
		test.insert(frequencies, letter);
	}

	test.inorder_print();

	infile.close();
}