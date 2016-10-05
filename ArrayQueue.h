// Code based on:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>

using namespace std;

template <typename E>
class ArrayQueue {
	enum { DEF_CAPACITY = 100 };		// default queue capacity
public:
	ArrayQueue(int cap = DEF_CAPACITY);		// constructor from capacity
	int size() const;				// number of items in the stack
	bool empty() const;				// is the stack empty?
	const E& front() const;	// get the top element
	void enqueue(const E& e);	// push element onto stack
	void dequeue();				// pop the stack
	void printAll();					// print all elements on stack to cout
private:                                	// member data
	E* Q;					// array of queue elements
	int capacity;			// queue capacity
	int f;					// index of the front of the queue
	int r;					// index of the rear of the queue
	int n;					// number of elements
};

template <typename E> ArrayQueue<E>::ArrayQueue(int cap)
	: Q(new E[cap]), capacity(cap), f(0), r(0), n(0) { }	// constructor from capacity

template <typename E> int ArrayQueue<E>::size() const
{
	return n;
}				// number of items in the queue

template <typename E> bool ArrayQueue<E>::empty() const
{
	return (n == 0);
}				// is the stack empty?

template <typename E>				// return element at front of queue
const E& ArrayQueue<E>::front() const {
	if (empty()) throw length_error("front of empty queue");
	return Q[f];
}

template <typename E>				// insert element to back of queue
void ArrayQueue<E>::enqueue(const E& e) {
	if (size() == capacity) throw length_error("enqueue to full queue");
	Q[r] = e;
	r = (r + 1) % capacity;
	n++;
}

template <typename E>				// remove element at back of queue
void ArrayQueue<E>::dequeue() {
	if (empty()) throw length_error("enqueue from empty queue");
	f = (f + 1) % capacity;
	n--;
}

// print all elements on queue
template <typename E>
void ArrayQueue<E>::printAll() {
	if (empty()) throw length_error("Empty queue");
	cout << "Elements in queue: ";
	int front = f;
	for (int i = 0; i < n; i++) {
		cout << "{" << Q[front] << "} ";
		front = (front + 1) % capacity;
	}
	cout << endl;
}