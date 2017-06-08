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