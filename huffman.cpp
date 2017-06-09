/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include "huffman.h"       // for HUFFMAN() prototype
#include "bnode.h"
#include "vector.h"        // for Vector
#include <fstream>
#include <string>
using namespace std;

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(std::string & fileName)
{
   // initialize variables
   Vector < Pair<string, float> > input;     // read the file into input
   List <Huffman*> hList;                    // keep a list of Huffman objects to combine them (pointers?)
   Huffman * hHead;			     // the head of the Huffman tree
   
   // Read the pairs into the vector
   
   // Read the pairs into hList OR create hList by searching for smallest in the vector
   
   // WHILE (!hList.size() > 1)
   
   // find 2 smallest frequencies
   
   // combine into hTree hHead and add that to the list
   
   // remove the 2 hTrees that were combined from the list (Or maybe the 1 tree, since add is void)
   
   // FOR 0 to vector.size()
	// call extract
	// output Huffman values in the order from the file
   return;
}

void readFile(string & fileName)
{
	string inputToken;
	double inputFrequency;
	Pair <double, string> huffmanSet;

	ifstream myFile;
	cerr << "FileName: " << fileName << endl;
	// TODO for some reason it cant accept a string as a file name.
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
			cerr << huffmanSet << endl;
			// add pair to list

		}
	myFile.close();
}
