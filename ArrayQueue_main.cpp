//
//  main for ArrayQueue
//

#include <iostream>
#include "ArrayQueue.h"

int main(int argc, const char * argv[]) {
	// create a stack
	ArrayQueue<int> intQueue;
	try {
		intQueue.enqueue(10);
		intQueue.enqueue(20);
		intQueue.enqueue(30);
		intQueue.enqueue(40);
		int size = intQueue.size();
		cout << "Size of the queue now: " << size << endl;
		cout << "front of the queue = " << intQueue.front() << endl;
		intQueue.printAll();
		intQueue.dequeue();
		intQueue.printAll();
		intQueue.enqueue(50);
		intQueue.printAll();
		intQueue.dequeue();
		intQueue.dequeue();
		intQueue.printAll();
		intQueue.enqueue(60);
		intQueue.printAll();
		intQueue.enqueue(70);
		intQueue.printAll();
		intQueue.enqueue(80);
		intQueue.printAll();
		intQueue.enqueue(90);
		intQueue.printAll();
	}
	catch (length_error &err) {
		cout << "Error condition: " << err.what() << endl;
	}
	try {
		bool isEmpty = intQueue.empty();
		cout << "Is queue empty (yes=true, no=false)? " << isEmpty << endl;
		cout << "front of the queue = " << intQueue.front() << endl;
		intQueue.printAll();
	}
	catch (length_error &err) {
		cout << "Error condition: " << err.what() << endl;
	}

	system("pause");
	return EXIT_SUCCESS;
}
