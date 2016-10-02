//
//  main for LinkedStack
//

#include <iostream>
#include "LinkedStack.h"

int main(int argc, const char * argv[]) {
   // create a stack
   LinkedStack<int> intStack;
   try {
      intStack.push(5);
      intStack.push(3);
      int size = intStack.size();
      cout << "Size of the stack now: " << size << endl;
      intStack.printAll();
      intStack.pop();
      intStack.printAll();
      intStack.push(7);
      intStack.printAll();
      intStack.pop();
      intStack.printAll();
	  cout << "Top of the stack = " << intStack.top() << endl;
      intStack.printAll();
      intStack.pop();
      intStack.printAll();
	  cout << "Top of the stack = " << intStack.top() << endl;
	  intStack.printAll();
   } catch (length_error &err) {
      cout << "Error condition: " << err.what() << endl;
   }
   try {
      intStack.top();
      intStack.printAll();
      bool isEmpty = intStack.empty();
      cout << "Is stack empty (yes=true, no=false)" << isEmpty << endl;
   } catch (length_error &err) {
      cout << "Error condition: " << err.what() << endl;
   }
   
   return EXIT_SUCCESS;
}
