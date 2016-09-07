
#pragma once

#include <stdexcept>

template <typename E>
class FixedVector {
private:
  int length;
  E* elements;

public:
  FixedVector(int length, E initial_value)
    throw(invalid_argument)
    : length(length) {
    if (length < 0) {
      throw invalid_argument("FixedVector length must be non-negative");
    } else {
      elements = new E[length];
      for (int i = 0; i < length; i++) {
        elements[i] = initial_value;
      }
    }    
  }

  ~FixedVector() { delete [] elements; }

  int getLength() const { return length; }

  E getIndex(int i) const throw(range_error) {
    if ((i < 0) || (i >= length)) {
      throw range_error("FixedVector::getIndex index out of range");
    } else {
      return elements[i];
    }
  }

  void setIndex(int i, E value) throw(range_error) {
    if ((i < 0) || (i >= length)) {
      throw range_error("FixedVector::getIndex index out of range");
    } else {
      elements[i] = value;
    }
  }
};
