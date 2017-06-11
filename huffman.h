/***********************************************************************

* Module:

* Lesson 07, Huffman

* Brother Helfrich, CS 235

* Author:

* Br. Helfrich

* Summary:

* This program will implement the huffman() function

************************************************************************/

#ifndef HUFFMAN_cpp

#define HUFFMAN_cpp

#include <string>

void huffman(const std::string & fileName);

#include <iostream>        // for CIN and COUT
#include <fstream>         // for IFSTREAM
#include <cassert>         // for ASSERT
#include <string>          // for STRING: binary representation of codes
#include "bnode.h"         // for BINARY_NODE class definition
#include "vector.h"        // for VECTOR container
#include "pair.h"          // for PAIR container

using namespace std;

/*******************************************************************
* HUFFMAN
* A huffman tree
******************************************************************/
class Huffman
{
public:
	Huffman()
	{
		tree = NULL;
	}
	Huffman(const Pair <string, float> & rhs) throw (bad_alloc)
	{
		tree = new BinaryNode < Pair <string, float> >(rhs);
	}
	Huffman(const string & first, float second) throw (bad_alloc)
	{
		Pair <string, float> pair(first, second);
		tree = new BinaryNode < Pair <string, float> >(pair);
	}
	~Huffman() { deleteBinaryTree(tree); }

	// add a sub-tree to our current tree
	inline void add(Huffman * pTree);

	// get the weight of the top-most element in the tree
	float getWeight() const { return tree->data.second; }

	// extract the values from the tree
	void extract(const Vector <Pair <string, float > > & input,
		Pair <string, string> output[])
	{
		extractRecursive(tree, string(""), input, output);
	}

private:
	// the recursive verson of extract
	void extractRecursive(BinaryNode < Pair <string, float> > * tree,
		string sPrefix,
		const Vector < Pair <string, float > > & input,
		Pair <string, string> output[]);

	BinaryNode < Pair <string, float> > * tree;
};
/****************************************************
* HUFFMAN :: ADD
* Add the subtree (pTree) to the current Huffman Tree
***************************************************/
inline void Huffman::add(Huffman * pTree)
{
	// allocate a new node, the parent
	BinaryNode < Pair <string, float> > * pNew =
		new BinaryNode < Pair <string, float> >;

	// the weight of the new node is the combination of the children's weight
	pNew->data.second = getWeight() + pTree->getWeight();

	// attach the left and right children to myself
	if (getWeight() <= pTree->getWeight())
	{
		pNew->pLeft = tree;
		pNew->pRight = pTree->tree;
	}
	else
	{
		pNew->pLeft = pTree->tree;
		pNew->pRight = tree;
	}

	// make the new tree the root and all
	tree = pNew;
}
/**********************************************
* HUFFMAN :: Extract Recursive
* The recursive version of extract
***********************************************/
//inline void Huffman::extractRecursive(BinaryNode<Pair<string, float> >* tree, string sPrefix,
//	const Vector<Pair<string, float> >& input, Pair<string, string> output[])
//{
//	if (NULL)
//		;
//	else
//		;
//}

void Huffman::printHuffmanCodes()
{
	// get Huffman codes from tree

	// place Huffman codes into a vector

	// print vector

}

string * Huffman::findRecursive(BinaryNode <Pair <string, float>> * tree, const string item)
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

#endif //HUFFMAN_cpp
