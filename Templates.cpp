
// Code from Kevin Wortman's lecture in week 3

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// First suppose we want to write functions for minimums of arrays. We
// could copy-paste code to write similar functions like so:

int MinimumOfInts(int array[], int count) throw(invalid_argument, length_error) {
  if (array == nullptr) {
    throw invalid_argument("minimum array must not be null");
  } else if (count < 1) {
    throw length_error("minimum array must be non-empty");
  } else {
    int smallest = array[0];
    for (int i = 1; i < count; i++) {
      if (array[i] < smallest)
        smallest = array[i];
    }
    return smallest;
  }
}

double MinimumOfDoubles(double array[], int count) throw(invalid_argument, length_error) {
  if (array == nullptr) {
    throw invalid_argument("minimum array must not be null");
  } else if (count < 1) {
    throw length_error("minimum array must be non-empty");
  } else {
    double smallest = array[0];
    for (int i = 1; i < count; i++) {
      if (array[i] < smallest)
        smallest = array[i];
    }
    return smallest;
  }
}

// However this copy-pasting violates the Don't Repeat Yourself (DRY)
// prinicple and is tedious and error-prone.

// It's better to define a single template function so that the
// compiler can "fill in the blanks" to synthesize these functions for
// us.

template <typename NUMBER>
NUMBER Minimum(NUMBER array[], int count) throw(invalid_argument, length_error) {
  if (array == nullptr) {
    throw invalid_argument("minimum array must not be null");
  } else if (count < 1) {
    throw length_error("minimum array must be non-empty");
  } else {
    NUMBER smallest = array[0];
    for (int i = 1; i < count; i++) {
      if (array[i] < smallest)
        smallest = array[i];
    }
    return smallest;
  }
}

// We can do the same thing for a template class.

template <typename ELEMENT>
class TwoOf {
private:
  ELEMENT first, second;

public:
  TwoOf(ELEMENT first, ELEMENT second)
    : first(first), second(second) { }

  ELEMENT getFirst() { return first; }
  ELEMENT getSecond() { return second; }

  void setFirst(ELEMENT first) { this->first = first; }
  void setSecond(ELEMENT first) { this->second = second; }
};

int main() {
  // Demo instantiating template function
  float fractions[4] = { 201.6, 33.8, 409.1, 66.9 };
  // This instantiates Minimum substituting ELEMENT=float
  cout << Minimum(fractions, 4) << endl; // prints out 33.8
  char characters[9] = "platypus"; // length is 9 to leave space for
                                   // the null terminator
  // This instantiates Minimum substituting ELEMENT=char
  cout << Minimum(characters, 8) << endl; // prints out a

  // Demo instantiating template class
  // Instantiate TwoOf substituting ELEMENT=double
  TwoOf<double> a(3.7, 9.1);
  // Instantiate TwoOf substituting ELEMENT=string
  TwoOf<string> b("cat", "dog");
  // prints 3.7 9.1 cat dog
  cout << a.getFirst() << ' '
       << a.getSecond() << ' '
       << b.getFirst() << ' '
       << b.getSecond() << endl;
  
  return 0;  
}
