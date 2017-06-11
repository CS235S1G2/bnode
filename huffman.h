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
inline void Huffman::extractRecursive(BinaryNode<Pair<string, float> >* tree, string sPrefix,
	const Vector<Pair<string, float> >& input, Pair<string, string> output[])
{
	if (NULL)
		;
	else
		;
}

//**********************************************
// * PAIR
// * This class couples together a pair of values, which may be of
// * different types (T1 and T2). The individual values can be
// * accessed through its public members first and second.
// *
// * Additionally, when compairing two pairs, only T1 is compared. This
// * is a key in a name-value pair.
// ***********************************************/
//template <class T1, class T2>
//class Pair
//{
//public:
//   // constructors
//  Pair() : first(), second() {}
//   Pair(const T1 & first, const T2 & second) : first(first), second(second) {}
//   Pair(const Pair <T1, T2> & rhs) : first(rhs.first), second(rhs.second) {}
//
//   // copy the values
//   Pair <T1, T2> & operator = (const Pair <T1, T2> & rhs)
//   {
//      first  = rhs.first;
//      second = rhs.second;
//      return *this;
//   }
//
//   // constant fetchers
//   const T1 & getFirst()  const { return first;  }
//   const T2 & getSecond() const { return second; }
//   
//   // compare Pairs.  Only first will be compared!
//   bool operator >  (const Pair & rhs) const { return first >  rhs.first; }
//   bool operator >= (const Pair & rhs) const { return first >= rhs.first; }
//   bool operator <  (const Pair & rhs) const { return first <  rhs.first; }
//   bool operator <= (const Pair & rhs) const { return first <= rhs.first; }
//   bool operator == (const Pair & rhs) const { return first == rhs.first; }
//   bool operator != (const Pair & rhs) const { return first != rhs.first; }
//   
//   // these are public.  We cannot validate!
//   T1 first;
//   T2 second;
//};
//
///*****************************************************
// * PAIR INSERTION
// * Display a pair for debug purposes
// ****************************************************/
//template <class T1, class T2>
//inline std::ostream & operator << (std::ostream & out, const Pair <T1, T2> & rhs)
//{
//   out << '(' << rhs.first << ", " << rhs.second << ')';
//   return out;
//}
//
///*****************************************************
// * PAIR EXTRACTION
// * input a pair
// ****************************************************/
//template <class T1, class T2>
//inline std::istream & operator >> (std::istream & in, Pair <T1, T2> & rhs)
//{
//   in >> rhs.first >> rhs.second;
//   return in;
//}

#endif //HUFFMAN_cpp
