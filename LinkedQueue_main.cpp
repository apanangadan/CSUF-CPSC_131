//
//  main for LinkedQueue
//

#include <iostream>
#include "LinkedQueue.h"

int main(int argc, const char * argv[]) {
   // create a stack
	LinkedQueue<int> intQueue;
   try {
		intQueue.enqueue(5);
		intQueue.enqueue(3);
		int size = intQueue.size();
		cout << "Size of the queue now: " << size << endl;
		intQueue.printAll();
		intQueue.dequeue();
		intQueue.printAll();
		intQueue.enqueue(7);
		intQueue.printAll();
		intQueue.dequeue();
		cout << "front of the queue = " << intQueue.front() << endl;
		intQueue.dequeue();
		cout << "front of the queue = " << intQueue.front() << endl;
		intQueue.printAll();
   } catch (length_error &err) {
		cout << "Error condition: " << err.what() << endl;
   }
   try {
		bool isEmpty = intQueue.empty();
		cout << "Is queue empty (yes=true, no=false)? " << isEmpty << endl;
		cout << "front of the queue = " << intQueue.front() << endl;
	    intQueue.printAll();
   } catch (length_error &err) {
		cout << "Error condition: " << err.what() << endl;
   }
   
//   system("pause");
   return EXIT_SUCCESS;
}
