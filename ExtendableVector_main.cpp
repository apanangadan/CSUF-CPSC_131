//
//  main.cpp for ExtendableArray
//

#include <iostream>
#include "ExtendableVector.h"

using namespace std;

int main(int argc, const char * argv[]) {
   // create an extendable vector
   ExtendableVector<int> myVector;

   // check the vector capacity
   cout << "Vector capacity: " << myVector.getCapacity() << endl;
   // check if myVectory is empty
   cout << "Is myVector empty (1: yes, 0: no): " << myVector.empty() << endl;
   
   // insert 7 to first slot
   int nElem = 0;
   myVector.insert(nElem, 7);
   cout << endl << "Element[" << nElem << "]: " << myVector[nElem] << endl;
   // insert 4 to 2nd slot
   myVector.insert(nElem, 4);
   
   // get the size of myVector and print all elements using []
   nElem = myVector.size();
   cout << endl << "My vector size: " << nElem << endl;
   for (int i = 0; i < myVector.size(); i++) {
      cout << "Element[" << i << "]: " << myVector[i] << endl;
   }
   
   // insert 2 to 3rd slot
   myVector.insert(2, 2);
   
   // get the size of my Vector
   nElem = myVector.size();
   cout << endl << "My vector size: " << nElem << endl;
   // get and print the last element using at
   int lastElem = nElem - 1;
   cout << "Last Element[" << lastElem << "]: " << myVector.at(lastElem) << endl;
   
   // check the vector capacity
   cout << endl << "Vector capacity: " << myVector.getCapacity() << endl;
   // print all elements
   for (int i = 0; i < myVector.size(); i++) {
      cout << "Element[" << i << "]: " << myVector[i] << endl;
   }
   
   // replace 7 with 5 using []
   int secondSlot = 1;
   cout << endl << "replace element[" << secondSlot << "]= " << myVector[secondSlot];
   myVector[secondSlot] = 5;
   cout << " with " << myVector[secondSlot] << " using [] operator" << endl;
   
   // replace 2 with 8 using at
   int thirdSlot = secondSlot + 1;
   cout << endl << "replace element[" << thirdSlot << "]= " << myVector[secondSlot];
   myVector.at(thirdSlot) = 8;
   cout << " with " << myVector[thirdSlot] << " using at operation" << endl;
   
   // insert 9
   myVector.insert(myVector.getCapacity() - 1, 9);
   // print all elements
   for (int i = 0; i < myVector.size(); i++) {
      cout << "Element[" << i << "]: " << myVector[i] << endl;
   }
   
   // error occurs when accessing past last element index
   try {
	   cout << "accessing element at capacity - expecting out of bounds error - " << endl;
       cout << myVector[myVector.getCapacity()];
   }
   catch (range_error & err) {
      cout << "Error condition: " << err.what() << endl;
   }
   
   // remove first element
   int firstSlot = 0;
   // print all elements
   cout << endl << "Removing Element[" << firstSlot << "]: " << myVector[firstSlot] << endl;
   myVector.erase(0);
   for (int i = 0; i < myVector.size(); i++) {
      cout << "Element[" << i << "]: " << myVector[i] << endl;
   }
   
   // create a vector of size 2
   ExtendableVector<int> myVector2(2);
   // check the vector capacity
   cout << "\n2nd vector capacity: " << myVector2.getCapacity() << endl;
   for (int i = 0; i < myVector2.size(); i++) {
      cout << "Element[" << i << "]: " << myVector2[i] << endl;
   }
   myVector2 = myVector;
   // My second vector
   cout << "My 2nd vector after setting it to my 1st vector: " << endl;
   for (int i = 0; i < myVector2.size(); i++) {
      cout << "Element[" << i << "]: " << myVector2[i] << endl;
   }
   
   // Pause and ask user to enter any character to exit
   char aChar;
   cout << "Enter any character to exit: ";
   cin >> aChar;
   cout << "Bye\n";
   
   return EXIT_SUCCESS;
}
