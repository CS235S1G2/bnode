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
/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(std::string fileName)
{
	string input;
   // read values into a Binary Tree
	ifstream myFile;
	cerr << "FileName: " << fileName << endl;
	myFile.open("/home/cs235/week08/huffman1.txt");
	if (myFile.is_open())
	{
		while (getline(myFile, input))
		{
			// store items in tree
		}
		myFile.close();
	}
	else
		cerr << "Unable to open file\n";
   // Generate Huffman Codes
   
   // Display resulting Huffman Codes
   return;
}
