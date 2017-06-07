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
#include <fstream>
#include "pair.h"
#include "bnode.h"
#include "vector.h"
using namespace std;
class Huffman
{
public:
	Huffman(BinaryNode<Pair<double, string>> newNode) { huffmanTree = NULL; 
	nodeVector = new Vector <BinaryNode<Pair<double, string>>>; 
	nodeVector->insert(newNode); }                                            // Default constructor
	void addNode(BinaryNode<Pair<double, string>>) {}

	

//private:
	BinaryNode <Pair<double, string>> *huffmanTree;
	// A vector of nodes
	Vector <BinaryNode<Pair<double, string>>> *nodeVector;

};

void huffman(std::string fileName);

#endif // HUFFMAN_h
