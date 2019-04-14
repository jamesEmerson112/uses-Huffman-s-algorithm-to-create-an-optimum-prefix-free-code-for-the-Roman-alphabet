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

#include <iostream>
#include <queue>
#include <string>
#include <vector>

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
void printCodes(struct HuffNode* root, string str)
{

	if (!root)
		return;

	if (root->letter != '%')
		cout << root->letter << ": " << str << "\n";

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
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

	printCodes(HuffmanQueue.top(), "");
}

int main() 
{ 
  
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
	HuffmanConstruction(freq, arr, size);
  
	system("pause");
    return 0; 
} 