//
//  main for LinkedStack
//

#include <iostream>
#include "LinkedStack.h"

int main() {
   // create a stack
   LinkedStack<int> intStack;
   try {
      // add 2 elements to stack
      intStack.push(5);
      intStack.push(3);
      // check if stack is not empty
      bool isEmpty = intStack.empty();
      cout << "Is stack empty (1=yes, 0=no) " << isEmpty << endl;
      // get the current stack size
      int size = intStack.size();
      cout << "Current stack size: " << size << endl;
      // print the top element
      intStack.printTop();
      
      // pop the top element
      intStack.pop();
      // get the current stack size
      size = intStack.size();
      cout << "Current stack size after pop: " << size << endl;
      // print the top element
      intStack.printTop();

      // add another element to stack
      intStack.push(7);
      // print the top element
      cout << "Add an element to ";
      intStack.printTop();

      // pop the top element
      intStack.pop();
      // get the current stack size
      size = intStack.size();
      cout << "Current stack size after pop: " << size << endl;
      
      // get the top element
      intStack.top();
      // print the top element
      intStack.printTop();

      // pop the top element
      intStack.pop();
      // pop again which would throw an error indicating pop from empty stack
      cout << "pop again - this would throw an error" << endl;
      intStack.pop();
   } catch (length_error &err) {
      cout << "Error condition: " << err.what() << endl;
   }
   try {
      // check if stack is empty
      bool isEmpty = intStack.empty();
      cout << "Is stack empty (1=yes, 0=no) " << isEmpty << endl;
      cout << "Error would be thrown when calling top()" << endl;
      // get the top element
      intStack.top();
   } catch (length_error &err) {
      cout << "Error condition: " << err.what() << endl;
   }
   
   // Pause and ask user to enter any character to exit
   char aChar;
   cout << "Enter any character to exit: ";
   cin >> aChar;
   cout << "Bye\n";

   return EXIT_SUCCESS;
}
