/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/
// TODO suggested from project overview
//       * create a Huffman class
//       * implement using pair class
#include "huffman.h"       // for HUFFMAN() prototype
#include "pair.h"
using namespace std;
// TODO four functions: readFile(also inserts into list
//                       sortList(creates Huffman Trees)
//                       display(generates huffman code)
//                       huffman: driver program

// GLOBAL VARIABLES?
// TODO add huffmanTree class definition here
//List <Pair> huffmanSets;

void readFile(string fileName)
{

}

void sortList()
{

}

void display()
{

}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(string fileName)
{
	string inputToken;
	double inputFrequency;
	Pair <double, string> huffmanSet;
   // read values into a Binary Tree
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
   // Generate Huffman Codes
   
   // Display resulting Huffman Codes
}
