/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Nathan Bench, Jed Bilman, Jeremy Chandler, Justin Chandler
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "huffman.h"       // for HUFFMAN() prototype
#include "bnode.h"
#include "vector.h"        // for Vector
#include "list.h"	   // for List
#include <fstream>
#include <string>
using namespace std;


/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(const std::string & fileName)
{
	// initialize variables
	Vector < Huffman* > input;     // read the file into input

	List <Huffman*> hList;                    // keep a list of Huffman objects to combine them (pointers?)
	Huffman * hHead;			     // the head of the Huffman tree



	string inputToken;
	double inputFrequency;
	Pair <float, string> huffmanSet;
	// Read the pairs into the vector

	ifstream fin("/home/cs235/week08/huffman1.txt");
	if (fin.fail())
		cerr << "Unable to open file\n";
	else
		while (fin >> inputToken)
		{
			// add name to pair
			huffmanSet.second = inputToken;
			// add value to pair
			fin >> inputFrequency;
			huffmanSet.first = inputFrequency;
			// error checking
			cerr << "Error Handling- Huffman Set: " << huffmanSet << endl;
			// add pair to list
			Huffman * pNew = new Huffman(inputToken, inputFrequency);
			input.push_back(pNew);

		}
	fin.close();

	// Read the pairs into hList OR create hList by searching for smallest in the vector
	// WHILE (!hList.size() > 1)
	while (input.size() > 0)
	{
		// find 2 smallest frequencies
		int smallest = 0;
		int secondSmallest = 0;
		for (int i = 1; i < input.size(); i++)
		{
			if (input[i]->getWeight() <= input[smallest]->getWeight())
				smallest = i;
			else if (input[i]->getWeight() <= input[secondSmallest]->getWeight())
				secondSmallest = i;
		}

		// combine into hTree hHead and add that to the list
		Huffman * secondSmallestH = input[secondSmallest];
		input[smallest]->add(input[secondSmallest]);
		input[secondSmallest] = input[input.size()];
		//change last to this position and delete the end
		delete input[input.size()];
	}

   // remove the 2 hTrees that were combined from the list (Or maybe the 1 tree, since add is void)
   
   // FOR 0 to vector.size()
	// call extract
	// output Huffman values in the order from the file
   return;
}

void Huffman::printHuffmanCodes()
{
	// get Huffman codes from tree

	// place Huffman codes into a vector

	// print vector

}

string * Huffman::findRecursive(BinaryNode <Pair <string, float> > * tree, const string item)
{
	string huffman1(""); // one huffman code
	string *huffmanCode = NULL; // pointer to the huffman code which will be passed on
	if (tree->pLeft != NULL)  //if there is a node to the left GO LEFT
	{
		huffmanCode->append("0");// add 0 to huffman code
		findRecursive(tree->pLeft, item); // repeate process
	}
	if (tree->pRight != NULL) //if there is a node to the right GO RIGHT
	{
		huffmanCode->append("1");// add 1 to huffman code
		findRecursive(tree->pRight, item); // repeate process
	}
	if (tree->pRight == NULL && tree->pLeft == NULL) // This is a leaf
	{
		huffmanCode = &huffman1;
	}
	return huffmanCode;
}
void readFile(string & fileName)
{
	//string inputToken;
	//double inputFrequency;
	//Pair <double, string> huffmanSet;

	//ifstream myFile;
	//cerr << "FileName: " << fileName << endl;
	//// TODO for some reason it cant accept a string as a file name.
	//ifstream fin("/home/cs235/week08/huffman1.txt");
	//if (fin.fail())
	//	cerr << "Unable to open file\n";
	//else
	//	while (fin >> inputToken)
	//	{
	//		// add name to pair
	//		huffmanSet.second = inputToken;
	//		// add value to pair
	//		fin >> inputFrequency;
	//		huffmanSet.first = inputFrequency;
	//		// error checking
	//		cerr << huffmanSet << endl;
	//		// add pair to list

	//	}
	//myFile.close();
}
#endif //HUFFMAN_H
