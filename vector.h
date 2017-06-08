/***********************************************************************
* Header:
*    Vector
* Summary:
*    This class contains the notion of a vector: a container
*    that expands as more items are put inside.
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

// forward declaration for VectorIterator
template <class T>
class VectorIterator;

/************************************************
 * VECTOR
 * A class that holds stuff
 ***********************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), vCapacity(0), data(NULL) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        { if (vCapacity) delete [] data; }
   
   // is the container currently empty
   bool empty() const  { return numItems == 0;         }

   // remove all the items from the container
   void clear()        { numItems = 0;                 }

   // how many items can the vector currently contain?
   int capacity() const { return vCapacity;             }
   
   // how many items are currently in the container?
   int size() const    { return numItems;              }

   // add an item to the container
   void push_back(const T & t) throw (const char *);
   
   // look up an item using the array index operator '[]'
   T & operator [] (int index);
   T & operator [] (int index) const;
   
   // assignment operator '='
   T & operator = (const T & rhs);
   
   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}
   
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
   
  private:
   T * p;
};

/*******************************************
 * VECTOR :: COPY CONSTRUCTOR
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
 * VECTOR : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int capacity) throw (const char *)
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

   // initialize the container by calling the default constructor
   for (int i = 0; i < vCapacity; i++)
      data[i] = T();
}

/***************************************************
 * VECTOR :: PUSH BACK
 * Insert an item on the end of the container
 **************************************************/
template <class T>
void Vector <T> :: push_back(const T & t) throw (const char *)
{
   T * tempArray;
   if (vCapacity == 0)
   {
      vCapacity = 1;
      try
      {
         data = new T[vCapacity];
      }
      catch (bad_alloc)
      {
         throw "ERROR: unable to allocate a new buffer for Vector";
      }
   }
   if (vCapacity == numItems)
   {
      vCapacity *= 2;
      try
      {
         tempArray = new T[vCapacity];
         
         // copy everything over
         for (int i = 0; i < numItems; i++)
         {
            tempArray[i] = data[i];
         }

         // free old memory
         delete[] data;

         // point to our new array
         data = tempArray;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for Vector";
      }
   }
   
   // add an item to the end
   data[numItems++] = t;
}


#endif // VECTOR_H

