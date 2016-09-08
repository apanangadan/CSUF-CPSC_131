
// Code from Kevin Wortman's lecture in weeks 2-3

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

// Example of a class with data members, setter and getter functions,
// constructor, initializer list, and reference data members.
class Student {
 private:
  double gpa;
  int cwid;
  string& campus; // Since this is a reference, it MUST be initialized
                  // with an initializer list in the constructor.

 public:
  // constructor
 Student(double gpa, int cwid, string& campus)
   : gpa(gpa), cwid(cwid), campus(campus) { }

  // destructor
  ~Student() { }

  // accessor / getter
  double getGpa() const { return gpa; }
  int getCwid() const { return cwid; }

  // mutator / setter
  void setCwid(int newCwid) { cwid = newCwid; } 

  // We intentionally do not create a setGpa() setter because GPAs are
  // read-only.
};

// Example of a function that does error checking with exceptions.
int minimum(int array[], int count) throw(invalid_argument, length_error) {
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

int main() {
  // Demo of creating class instance object and using getter and
  // setter functions.
  string shared_campus_name = "CSU Fullerton";
  Student a(4.0, 820123, shared_campus_name);
  Student b(3.7, 820124, shared_campus_name);
  cout << a.getGpa() << endl;
  a.setCwid(123);
  cout << a.getCwid() << endl;

  // Demo of try-catch blocks around functions that throw.
  int values[5] = {3, 4, -8, 7, 9};
  try {
    cout << "Minimum: " << minimum(values, 5) << endl; // prints -8
  } catch (exception e) {
    cout << "Strange, no exception should have been thrown!" << endl;
  }
  // intentionally trigger a length_exception
  try {
    cout << "Minimum: " << minimum(values, 0) << endl; // throws exception
  } catch (invalid_argument e) {
    cout << "invalid argument error: " << e.what() << endl; // skip over this
  } catch (length_error e) {
    // jump here and print
    // length error: minimum array must be non-empty
    cout << "length error: " << e.what() << endl;
  }

  return 0;
}
