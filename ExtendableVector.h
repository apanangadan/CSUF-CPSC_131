//
// ExtendableVector.h
// ExtendableVector class using code from
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
//

#pragma once

#include <stdexcept>
#include <algorithm> // needed for std::max in ExtendableVector::insert()

using namespace std;

const int DEFAULT_VECTOR_CAPACITY = 100;

template <typename ELT>
class ExtendableVector {
public:
   // length copies of default_value
   ExtendableVector(int length = DEFAULT_VECTOR_CAPACITY) {
      if (length <= 0) throw invalid_argument("length <= 0");
      capacity = length;
      numberOfElements = 0;
      elements = new ELT[length];
   }
   
   // copy constructor
   ExtendableVector(const ExtendableVector& a) {
      capacity = a.capacity;
      numberOfElements = a.numberOfElements;
      elements = new ELT[numberOfElements];
      for (int i = 0; i < numberOfElements; i++) {
         elements[i] = a.elements[i]; }
   }
   
   ~ExtendableVector() { delete[] elements; }
   
   // assignment operator from another extendable vector
   ExtendableVector& operator=(const ExtendableVector& theVect) {
      if (this != &theVect) {	// avoid self-assignment
         delete[] elements;       // delete old array
         capacity = theVect.capacity;  // set the capacity
         elements = new ELT[capacity]; // allocate new array
         numberOfElements = theVect.numberOfElements; // set the size
         for (int i = 0; i < numberOfElements; i++) {
            elements[i] = theVect.elements[i]; // copy the vector contents
         }
      }
      return *this;
   }
   
   int size() { // returns number of elements
      return numberOfElements; }
   
   bool empty() { // is vector empty?
      return (numberOfElements == 0); }
   
   int getCapacity() {
      return capacity;
   }
   
   ELT& operator[](int index) { // element at index i
      return at(index);
   }
   
   ELT& at(int index) { // element at index i
      if ((index < 0) || (index >= numberOfElements)) {
         throw range_error("index out of bounds"); }
      return elements[index];
   }
   
   void erase(int i) { // remove element at index i
      for (int j = i+1; j < numberOfElements; j++) {
         elements[j-1] = elements[j]; // shift elements down
      }
      numberOfElements--; // one fewer element
   }
   
   void reserve(int N) { // reserve a least N slots
      if (capacity >= N) { // already big enough
         return;
      }
      ELT *newArray = new ELT[N]; // allocate bigger array
      for (int j = 0; j < numberOfElements; j++) {
         newArray[j] = elements[j]; // copy contents to new array
      }
      if (elements != nullptr) { // discard old array
         delete [] elements;
      }
      elements = newArray; // have extendable array point to new array
      capacity = N; // set new capacity
   }
   
   void insert(int index, ELT value) {
      if (index < 0) throw range_error("index out of bounds");
      if (numberOfElements >= capacity) // overflow?
         reserve(max(1, 2 * capacity)); // double current array size
      for (int j = numberOfElements-1; j >= index; j--) {
         elements[j+1] = elements[j]; // shift elements up
      }
      elements[index] = value;
      numberOfElements++;
   }
   
private:
   int capacity;               // current array size
   int numberOfElements;       // number of elements in vector
   ELT *elements;              // array storing elements
};

