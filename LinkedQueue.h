// Code based on:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>
#include "DLinkedList.h"

using namespace std;

template <typename E>				// queue element type
class LinkedQueue {				// queue as doubly linked list
public:
	LinkedQueue();				// constructor
	int size() const;				// number of items in the queue
	bool empty() const;				// is the queue empty?
	E& front();						// get the front element
	void enqueue(const E& e);		// enqueue element at rear
	void dequeue();					// dequeue element at front
	void printAll();				// print front element
private:					// member data
	DLinkedList<E> D;				// linked list of elements
	int n;					// number of elements
};

template <typename E>
LinkedQueue<E>::LinkedQueue()			// constructor
	: D(), n(0) { }

template <typename E>
int LinkedQueue<E>::size() const			// number of items in the queue
{
	return n;
}

template <typename E>
bool LinkedQueue<E>::empty() const		// is the queue empty?
{
	return n == 0;
}

// get the front element
template <typename E>
E& LinkedQueue<E>::front() {
	if (empty())
		throw length_error("front of empty queue");
	return D.front();				// list front is queue front
}

// enqueue element at rear
template <typename E>
void LinkedQueue<E>::enqueue(const E& e) {
	D.addFront(e);					// insert after cursor
	n++;
}

// dequeue element at front
template <typename E>
void LinkedQueue<E>::dequeue() {
	if (empty())
		throw length_error("dequeue of empty queue");
	D.removeBack();					// remove from list front
	n--;
}

// print front element of queue
template <typename E>
void LinkedQueue<E>::printAll() {
	if (empty()) throw length_error("Empty queue");
	cout << "Front of queue: {" << D.front() << "}" << endl;
}