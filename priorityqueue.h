//*******************************************************
//
// An T. Vo
// CS 302 - 1002, November 6th 2018
// Assignment #6
//
//*******************************************************

/* creating a priority queue to do Huffman algorithm
 * it's going to store every input item into a certain order
 * hopefully I can figure Dr. Larmore's way of doing this soon
 */

// how do I store nodes into a queue

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "binarytree.cpp"

using namespace std;

struct linkedList
{
	int frequency;
	char letter;
	linkedList *next;
}

class priority_queue
{
private:
	node *linkedList;
	int length;
public:
};