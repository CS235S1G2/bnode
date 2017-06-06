

#ifndef BINARY_TREE
#define BINARY_TREE
#include "iostream"
/***********************************************
 * BINARY NODE
 * A node to be used in a binary tree. 
 **********************************************/
template <class T>
class BinaryNode
{
public:
	BinaryNode() {}
	BinaryNode(const T & t) : data(t) {}
private:
	T data;
};

/****************************************************
* BINARY TREE
* A group of binary nodes conected using pointers
****************************************************/
template <class T>
class BinaryTree
{
   public:
      // constructors
      BinaryTree(): pParent(NULL), pLeft(NULL), pRight(NULL)
      {
         data = T();
      }
      BinaryTree(const T & t): 
         BinaryNode(t), pParent(NULL), pLeft(NULL), pRight(NULL) {}
      
      // methods
      void addLeft (BinaryNode <T> * pNode, BinaryNode <T> * pAdd);
      void addRight(BinaryNode <T> * pNode, BinaryNode <T> * pAdd);
      void addLeft (BinaryNode <T> * pNode, const T & t) throw (const char *);
      void addRight(BinaryNode <T> * pNode, const T & t) throw (const char *);
      
      // members
      BinaryTree <T> * pParent;
      BinaryTree <T> * pLeft;
      BinaryTree <T> * pRight;
};

#endif BINARY_TREE

template<class T>
// nonmember function prototypes
void deleteBTree(BinaryNode <T> * & pNode)
{

}

template <class T>
std::ostream & operator << (std::ostream & out, const BinaryTree <T> * rhs)
{

}
