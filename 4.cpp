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

/* instead of utilizing nodes with binary trees like the map
 * now using soly with struct with a completely different approach
 */

// 5th version: reading input


#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

const int ORIGINAL_NUMBER_OF_NODES = 27;
// A Huffman tree node !?
struct HuffNode
{
	int frequency;
	char letter;

	HuffNode *left, *right;

	HuffNode(int frequency, char letter)
	{
		left = NULL;
		right = NULL;
		this->frequency = frequency;
		this->letter = letter;
	}
};

struct compare 
{
	bool operator()(HuffNode *left, HuffNode *right)
	{
		return (left->frequency > right->frequency);
	}
};

// print binary code
void printBinaryData(struct HuffNode* root, string str)
{
	if (!root)
		return;

	printBinaryData(root->left, str + "0");
	printBinaryData(root->right, str + "1");
	if (root->letter != '%')
		cout << root->letter << ": " << str << "\n";
}

void printFrequency(struct HuffNode* root)
{
	if (!root)
		return;	
	
	if (root->letter != '%')
		cout << root->letter << ": " << root->frequency << "\n";
	printFrequency(root->left);
	printFrequency(root->right);

}

// the construction of a Huffman Tree
void HuffmanConstruction(int frequency[], char letter[], int size)
{
	struct HuffNode *left, *right, *top;

	priority_queue<HuffNode*, vector<HuffNode*>, compare> HuffmanQueue;

	for (int i = 0; i < size; ++i)
	{
		HuffmanQueue.push(new HuffNode(frequency[i], letter[i]));
	}

	while (HuffmanQueue.size() != 1)
	{
		left = HuffmanQueue.top();
		HuffmanQueue.pop();

		right = HuffmanQueue.top();
		HuffmanQueue.pop();

		top = new HuffNode(left->frequency + right->frequency, '%');

		top->left = left;
		top->right = right;

		HuffmanQueue.push(top);
	}

	printBinaryData(HuffmanQueue.top(), "");
	printFrequency(HuffmanQueue.top());
}

//******************************************************************************************
void readInput();

int main() 
{ 
    
    readInput();
  
	system("pause");
    return 0; 
} 

void readInput()
{
	// declaring variables
	char letter[ORIGINAL_NUMBER_OF_NODES];
	for (int i = 0; i < ORIGINAL_NUMBER_OF_NODES; ++i)
	{
		letter[i] = '%';    // as in % is the initilizing value
	}
	
	int frequencies[ORIGINAL_NUMBER_OF_NODES];
	for (int i = 0; i < ORIGINAL_NUMBER_OF_NODES; ++i)
	{
		frequencies[i] = 0;
	}

	int index = 0;

	// variable for the ifstream
	ifstream infile;

	// open file
	infile.open("frequencies.txt");

	// check if the file is correct
	if (!infile)
	{
		cout << "Wrong input file" << endl;
		return;
	}

	infile >> frequencies[index];
	letter[index] = ' ';
	index++;
	while(!infile.eof())
	{
		infile >> letter[index] >> frequencies[index];
		index++;
	}

	HuffmanConstruction(frequencies, letter, index);
}