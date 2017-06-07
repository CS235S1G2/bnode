/***********************************************************************
* Header:
*    Vector
* Summary:
*    This class contains the notion of a Vector: a bucket to hold
*    data for the user. This is just a starting-point for more advanced
*    constainers such as the vector, set, stack, queue, deque, and map
*    which we will build later this semester.
*
*    This will contain the class definition of:
*        Vector         : A class that holds stuff
*        VectorIterator : An interator through Vector
* Author
*    Br. Helfrich
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <iostream>

// forward declaration for VectorIterator
template <class T>
class VectorIterator;

template<class T>
class VectorConstIterator;

/************************************************
 * VECTOR
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
	Vector() : numItems(0), vCapacity(0), data(NULL) {};

   // copy constructor : copy it
	Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int vCapacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (vCapacity) delete [] data; }
   
   // assignment operator
   Vector<T>& operator=(const Vector<T> &rhs) throw (const char *);
   
   // square bracket operator
   T& operator [](int index) throw (const char *);
   const T& operator [](int index) const throw (const char *);
   
   // is the Vector currently empty
   bool empty() const  { if (numItems == 0)return numItems == 0;
   else return numItems == 1;
   }


   // remove all the items from the Vector
   void clear()        { numItems = 0;                 }

   // how many items are currently in the Vector?
   int size() const    { return numItems;              }

   // add an item to the Vector
   void insert(const T & t) throw (const char *);
   void push_back(const T & t) throw (const char *);
   
   // return the capacity
   int capacity() const { return vCapacity; }

   // return an iterator to the beginning of the list
   VectorIterator <T> begin() const
		{ return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() const
		{ return VectorIterator<T>(data + numItems);}

   // return an iterator to the beginning of the list
   VectorConstIterator <T> cbegin() const
   {
	   return VectorConstIterator<T>(data);
   }

   // return an iterator to the end of the list
   VectorConstIterator <T> cend() const
   {
	   return VectorConstIterator<T>(data + numItems);
   }
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Vector?
   int vCapacity;      // how many items can I put on the Vector before full?
};

/**************************************************
 * VECTOR ITERATOR
 * An iterator through Vector
 *************************************************/
template <class T>
class VectorIterator
{
  public:
   // default constructor
  VectorIterator() : p(NULL) {}

   // initialize to direct p to some item
  VectorIterator(T * p) : p(p) {}

   // copy constructor
   VectorIterator(const VectorIterator & rhs) { *this = rhs; }

   // assignment operator
   VectorIterator & operator = (const VectorIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const VectorIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   VectorIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   VectorIterator <T> operator++(int postfix)
   {
      VectorIterator tmp(*this);
      p++;
      return tmp;
   }

   // prefix decrement
   VectorIterator <T> & operator --()
   {
	   p--;
	   return *this;
   }
   
  private:
   T * p;
};

/**************************************************
* VECTOR ITERATOR
* An iterator through Vector
*************************************************/
template <class T>
class VectorConstIterator
{
public:
	// default constructor
	VectorConstIterator() : p(NULL) {}

	// initialize to direct p to some item
	VectorConstIterator(T * p) : p(p) {}

	// copy constructor
	VectorConstIterator(const VectorConstIterator & rhs) { *this = rhs; }

	// assignment operator
	VectorConstIterator & operator = (const VectorConstIterator & rhs)
	{
		this->p = rhs.p;
		return *this;
	}

	// not equals operator
	bool operator != (const VectorConstIterator & rhs) const
	{
		return rhs.p != this->p;
	}

	// dereference operator
	T & operator * ()
	{
		return *p;
	}

	// prefix increment
	VectorConstIterator <T> & operator ++ ()
	{
		p++;
		return *this;
	}

	// postfix increment
	VectorConstIterator <T> operator++(int postfix)
	{
		VectorIterator tmp(*this);
		p++;
		return tmp;
	}

	// prefix decrement
	VectorConstIterator <T> & operator --()
	{
		p--;
		return *this;
	}

private:
	T * p;
};

/*******************************************
 * Vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
{
   assert(rhs.vCapacity >= 0);
   // do nothing if there is nothing to do
   if (rhs.vCapacity == 0)
   {
      vCapacity = numItems = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.vCapacity];
   }
   // if allocation error throw message
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.vCapacity);
   vCapacity = rhs.vCapacity;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < vCapacity; i++)
      data[i] = T();
}

/**********************************************
 * Vector : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Vector to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int vCapacity) throw (const char *)
{
   assert(vCapacity >= 0);
   
   // do nothing if there is nothing to do
   if (vCapacity == 0)
   {
      this->vCapacity = this->numItems = 0;
      this->data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[vCapacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->vCapacity = vCapacity;
   this->numItems = 0;

   // initialize the Vector by calling the default constructor
   for (int i = 0; i < vCapacity; i++)
      data[i] = T();
}

/**********************************************
* VECTOR : ASSIGNMENT OPERATOR
* Assigns one vector to another
**********************************************/
template<class T>
Vector<T>& Vector<T> :: operator=(const Vector<T>& rhs) throw(const char *)
{
  assert(rhs.vCapacity >= 0);
   // do nothing if there is nothing to do
   if (rhs.vCapacity == 0)
   {
      this->vCapacity = this->numItems = 0;
      this->data = NULL;
      //return;
   }

   // attempt to allocate
   try
   {
      this->data = new T[rhs.vCapacity];
   }
   // catch error message if cannot allocate buffer
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.vCapacity);
   this-> vCapacity = rhs.vCapacity;
   this-> numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
      this-> data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < vCapacity; i++)
      this-> data[i] = T();

	return *this;
};

/**********************************************
* VECTOR : BRACKET OPERATOR []
* used to access an item in the index
**********************************************/
template<class T>
T & Vector<T>::operator[](int index) throw(const char *)
{
   // check bounds
	if (index > numItems || index < 0)
		throw "ERROR: Invalid index";
	return data[index];
};

/****************************************************
* VECTOR : BRACKET OPERATOR []
* used to access an item in the index (with const)
****************************************************/
template<class T>
const T & Vector<T>::operator[](int index) const throw(const char *)
{
	// check bounds
	if (index > numItems || index < 0)
		throw "ERROR: Invalid index";
	return data[index];
};

/***************************************************
 * VECTOR :: INSERT
 * Insert an item on the end of the Vector
 **************************************************/
template <class T>
void Vector <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (vCapacity == 0 || vCapacity == numItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
* VECTOR :: PUSH_BACK
* Insert an item on the end of the Vector
**************************************************/
template<class T>
inline void Vector<T>::push_back(const T & t) throw(const char *)
{
   if (vCapacity == 0)
   {
      vCapacity = 1;
	  T * tempArray = new T[vCapacity];
	  for (int i = 0; i < numItems; i++)
	  {
		  tempArray[i] = data[i];
	  }
	  delete[] data;
	  data = tempArray;
   }
   else if (numItems >= vCapacity)
   {
	   vCapacity *= 2;
	   T * tempArray = new T[vCapacity];
	   for (int i = 0; i < numItems; i++)
	   {
		   tempArray[i] = data[i];
	   }
		   delete[] data;
		   data = tempArray;
   }
   try
   {
       data[numItems++] = t;
   }
   catch (std::bad_alloc)
   {
	   throw "ERROR: Unable to allocate a new buffer for Vector";
   }
}

#endif //  VECTOR_H
