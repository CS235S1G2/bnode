/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <iostream>
#include "bnode.h"

void huffman(std::string & fileName);

// forward declaration
template <class T1, class T2>
class Pair;

/**********************************************
 * Huffman
 * This class encapsulates a tree of Huffman values
 ***********************************************/
class Huffman
{
public:
   Huffman()
   {
      tree = NULL;
   }
   Huffman(const Pair <string, float> & rhs) throw (bad_alloc)
   {
      tree = new BinaryNode < Pair <string, float> > (rhs);
   }
   Huffman(const string & first, float second) throw (bad_alloc)
   {
      Pair <string, float> pair(first, second);
      tree = new BinaryNode < Pair <string, float> > (pair);
   }
   ~Huffman() { deleteBinaryTree(tree); }

   // add a sub-tree to our current tree
   void add(Huffman * pTree);

   // get the weight of the top-most element in the tree
   float getWeight() const  { return tree->data.second; }

   // extract the values from the tree
   void extract(const Vector <Pair <string, float > > & input,
                Pair <string, string> output [])
   {
      extractRecursive(tree, string(""), input, output);
   }

private:
   // the recursive verson of extract
   void extractRecursive(BinaryNode < Pair <string, float> > * tree,
                         string sPrefix,
                         const Vector < Pair <string, float > > & input,
                         Pair <string, string> output []);

   BinaryNode < Pair <string, float> > * tree;
};

/**********************************************
 * PAIR
 * This class couples together a pair of values, which may be of
 * different types (T1 and T2). The individual values can be
 * accessed through its public members first and second.
 *
 * Additionally, when compairing two pairs, only T1 is compared. This
 * is a key in a name-value pair.
 ***********************************************/
template <class T1, class T2>
class Pair
{
public:
   // constructors
  Pair() : first(), second() {}
   Pair(const T1 & first, const T2 & second) : first(first), second(second) {}
   Pair(const Pair <T1, T2> & rhs) : first(rhs.first), second(rhs.second) {}

   // copy the values
   Pair <T1, T2> & operator = (const Pair <T1, T2> & rhs)
   {
      first  = rhs.first;
      second = rhs.second;
      return *this;
   }

   // constant fetchers
   const T1 & getFirst()  const { return first;  }
   const T2 & getSecond() const { return second; }
   
   // compare Pairs.  Only first will be compared!
   bool operator >  (const Pair & rhs) const { return first >  rhs.first; }
   bool operator >= (const Pair & rhs) const { return first >= rhs.first; }
   bool operator <  (const Pair & rhs) const { return first <  rhs.first; }
   bool operator <= (const Pair & rhs) const { return first <= rhs.first; }
   bool operator == (const Pair & rhs) const { return first == rhs.first; }
   bool operator != (const Pair & rhs) const { return first != rhs.first; }
   
   // these are public.  We cannot validate!
   T1 first;
   T2 second;
};

/*****************************************************
 * PAIR INSERTION
 * Display a pair for debug purposes
 ****************************************************/
template <class T1, class T2>
inline std::ostream & operator << (std::ostream & out, const Pair <T1, T2> & rhs)
{
   out << '(' << rhs.first << ", " << rhs.second << ')';
   return out;
}

/*****************************************************
 * PAIR EXTRACTION
 * input a pair
 ****************************************************/
template <class T1, class T2>
inline std::istream & operator >> (std::istream & in, Pair <T1, T2> & rhs)
{
   in >> rhs.first >> rhs.second;
   return in;
}

#endif // HUFFMAN_h
