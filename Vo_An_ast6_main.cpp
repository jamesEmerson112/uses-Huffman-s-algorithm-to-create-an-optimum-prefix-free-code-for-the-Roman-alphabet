// This time instead of using the two arrays to find out which frequencies it is
// I'm gonna use the letter to search for the frequency THEN use the frequency to print out
// the binary code OR just add the string binary code for each letter lmao

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


/* Write a C++ program which encodes a file of paintext into a string of bits, using that Huffman code.
*/

/* Write a C++ program which decodes a string of bit sinto plaintext.
*/

/* 1. The program should first create the code, 
   2. then prompt the user to either encode or decode
   3. In either case, the user enters the name of the file (plaintext or code) to read,
   and the name of the file to write
   4. You could, instead, write the Huffman code into a file, then read that file to either encode or decode. 
   Dr. Larmore does not recommend this.
*/

#include "Vo_An_ast6_Huffman.h"
//************************
// checking if there is a memory leak
/*
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
*/
//************************

using namespace std;

const int ORIGINAL_NUMBER_OF_NODES = 27; // because there should be only 26 nodes to carry each letter from the alphabet
										 // and one node to hold "space"


//******************************************************************************************
void createTheCode(struct HuffNode*&, int[]);
// void function createTheNode will read the file of frequencies then construct
// the binary tree generated by Huffman algorithm with the given frequencies

void encodingPart(struct HuffNode*);
// void function encoding will take the generated Huffman tree, then prompt the user 
// the input the name of the input file and the name of the output file to write the 
// encrypted code

string encoding(struct HuffNode*,char);
// string encoding will encrypt the input text and return as an encrypted code

void decodingPart(struct HuffNode*);
// void function decoding will take the generated Huffman tree, then prompt the user 
// the input the name of the input file and the name of the output file to write the 
// decoding code

string decoding(struct HuffNode*, string);
// string decoing will encrypt the input text and return as an decoded code

void printAuthorName();

/* 1. The program should first create the code, 
   2. then prompt the user to either encode or decode
   3. In either case, the user enters the name of the file (plaintext or code) to read,
   and the name of the file to write
   4. You could, instead, write the Huffman code into a file, then read that file to either encode or decode. 
   Dr. Larmore does not recommend this.
*/

void step1(struct HuffNode*&);
void step2and3(struct HuffNode*&);

int main() 
{ 
	printAuthorName();
	// 1.
    struct HuffNode *completeHuffmanTree = NULL;
    step1(completeHuffmanTree);
 
 	// 2.
    step2and3(completeHuffmanTree);
    //*************

	free_memory(completeHuffmanTree);

	// _CrtDumpMemoryLeaks();  
	system("pause");
    return 0; 
} 
//******************************************************************************************
// ALGORITHM
/* 1. The program should first create the code, 
   2. then prompt the user to either encode or decode
   3. In either case, the user enters the name of the file (plaintext or code) to read,
   and the name of the file to write
   4. You could, instead, write the Huffman code into a file, then read that file to either encode or decode. 
   Dr. Larmore does not recommend this.
*/

void step1(struct HuffNode* &completeHuffmanTree)
// 1. The program should first create the code, 
{
   int frequencies[ORIGINAL_NUMBER_OF_NODES];
    for (int i = 0; i < ORIGINAL_NUMBER_OF_NODES; ++i)
    {
    	frequencies[i] = 0;
    }

    createTheCode(completeHuffmanTree, frequencies);
}

void step2and3(struct HuffNode* &completeHuffmanTree)
// 2. then prompt the user to either encode or decode
// 3. In either case, the user enters the name of the file (plaintext or code) to read,
// and the name of the file to write

{
    int choice = 0;
    string prompt1 = "Would you like to encode or decode?\nPlease:\nPress 1 to encode\nPress 2 to decode\n";    
    string prompt2 = "Press 9 to exit\n"; 
	cout << prompt1 << prompt2 << endl;
    cin >> choice;
    while(cin)
    {
	    if (choice == 1)
	    {
	    	encodingPart(completeHuffmanTree);
	    	cout << endl;
	    }
	    else if (choice == 2)
	    {
	    	decodingPart(completeHuffmanTree);
	    	cout << endl;
	    }
	    else if (choice == 9)
	    	break;
	    else
	    {
	    	cout << "Invalid choice. Please choose again" << endl;    
	    	cin >> choice;	
	    }
	    string prompt1 = "Would you like to encode or decode?\nPlease:\nPress 1 to encode\nPress 2 to decode\n";    
	    string prompt2 = "Press 9 to exit\n"; 
	    cout << prompt1 << prompt2;
	    cin >> choice;	    
    }
}

void printAuthorName()
{
	cout << setfill('*') << setw(80) << "*" << endl;
	cout << "An Thien Vo - CS 302 - Assignment #6\n";
	cout << "Huffman" << endl;
	cout << setfill('*') << setw(80) << "*" << endl;
}

//******************************************************************************************
void createTheCode(struct HuffNode* &completeHuffmanTree, int frequencies[])
// void function createTheNode will read the file of frequencies then construct
// the binary tree generated by Huffman algorithm
// Condition: a tree to have the value of the complete tree generated by Huffman
//  		  and the array that carries frequencies.
{
	// declaring variables
	char letter[ORIGINAL_NUMBER_OF_NODES];
	for (int i = 0; i < ORIGINAL_NUMBER_OF_NODES; ++i)					// larmore
	{
		letter[i] = '%';    // as in % is the initilizing value
	}
	
	int index = 0; 			// or size

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

	// storing inputs into arrays
	infile >> frequencies[index];
	letter[index] = ' ';
	index++;
	while(!infile.eof())
	{
		infile >> letter[index] >> frequencies[index];
		index++;
	}

	HuffmanConstruction(frequencies, letter, index, completeHuffmanTree);

	infile.close();
}

//****************************************************************************************** larmore
void encodingPart(struct HuffNode* HuffmanTree)
// void function encoding will take the generated Huffman tree, then prompt the user 
// the input the name of the input file and the name of the output file to write the 
// encrypted code
// Condition: a complete tree generated by Huffman
{
	// declaring variables
	string inputfile;
	string outputfile;
	ifstream infile;
	ofstream outfile;

	char text; 					// to hold the input data
	string str = "";			// string to hold the output string
	char endOfLine = ' '; 		// to print a space in the end of the line

	cout << "\nPlease enter the name of the file (plaintext)"
		 << " to read and the name of the file to write:" << endl;
	cin >> inputfile >> outputfile;
	inputfile += ".txt";
	outputfile += ".txt";

	// open file
	infile.open(inputfile.c_str());

	// take input and encode it
	while(infile.get(text))
	{
		str += encoding(HuffmanTree, text);
	}
	
	// GENERATE a SPACE in the END OF LINE
	str+= encoding(HuffmanTree, endOfLine);

	// printing out the output to the output file
	outfile.open(outputfile);
	for (int i = 0; i < static_cast<int>(str.size()) ; ++i)
	{
		if (i % 80 == 0 && i != 0)
			outfile << endl;
		outfile << str[i];
	}

	outfile << "\n";

	// close all files
	infile.close();
	outfile.close();
}

string encoding(struct HuffNode* root, char letter)
// string encoding will encrypt the input text and return as an encrypted code
// Condition: a complete tree generated by Huffman and the letter
//  		  that is searched
{
	/*
	 * 1. toupper the letter
	 * 2. find the letter
	 * 3. print the binary data
	 */
	// int countForPrintingEndline
	if (letter >= 97 && letter <= 122)
		letter = letter - 32;
	if (letter < 65 || letter > 90)
		letter = 32;
	// cout << letter; 

	string encoded_str;
	HuffNode *temp = root;
	HuffNode *tempLeft = root->left;
	HuffNode *tempRight = root->right;

	if (temp == NULL)
		return encoded_str;

	if (contains(tempLeft, letter) == true)
	{
		encoded_str += "0";
		encoded_str += encoding(tempLeft, letter);
	}
	else if (contains(tempRight, letter) == true)
	{
		encoded_str += "1";
		encoded_str += encoding(tempRight, letter);
	}

	return encoded_str;
}

void decodingPart(struct HuffNode* HuffmanTree)
// void function decoding will take the generated Huffman tree, then prompt the user 
// the input the name of the input file and the name of the output file to write the 
// decoding code
// Condition: a complete tree generated by Huffman
{
	// declaring variables
	string inputfile;
	string outputfile;
	ifstream infile;
	ofstream outfile;

	char bit;				// the bit number
	string str = ""; 		// the intput string that holds all of
							// the bit numbers
	string output = "";	 	// string to hold the output string

	cout << "\nPlease enter the name of the file (code)"
		 << " to read and the name of the file to write:" << endl;
	cin >> inputfile >> outputfile;
	inputfile += ".txt";
	outputfile += ".txt";

	// open input file
	infile.open(inputfile.c_str());

	// receive the input data
	while(infile >> bit)
	{
		str.push_back(bit);
	}

	// decoding
	output = decoding(HuffmanTree, str);

	outfile.open(outputfile);
	// outputing
	for (int i = 0; i < static_cast<int>(output.size()); ++i)
	{
		if(i % 80 == 0 && i != 0)
			outfile << "\n";
		outfile << output[i];
	}

	outfile << "\n";

	// close all the files
	infile.close();
	outfile.close();
}

string decoding(struct HuffNode* root, string bit)
// string decoing will encrypt the input text and return as an decoded code  Larmore
{
	/* basically if bit = 0, turn left, if left != '%', print character
	 * if bit = 1, turn right, if right != '%', print character
	 */
	string encoded_str = "";
	HuffNode *temp = root;
	for (int i = 0; i < static_cast<int>(bit.size()); ++i)
	{
		if (temp != NULL)
		{
			if(is_leaf(temp) && temp->letter != '%')
			{
				encoded_str.push_back(temp->letter);
				temp = root;
			}
			if(bit[i] == '0') 		// left child
				temp = temp->left;
			if(bit[i] == '1')
				temp = temp->right;
		}
	}

	return encoded_str;
}

