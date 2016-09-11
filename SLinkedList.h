// Code from:
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//

#pragma once

#include <stdexcept>

using namespace std;

template <typename E> class SLinkedList;	// forward declaration to be used when declaring SNode

template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E> *next;				// next item in the list
	friend class SLinkedList<E>;		// provide SLinkedList access
};

template <typename E>
class SLinkedList {				// a singly linked list
public:
	SLinkedList();				// empty list constructor
	~SLinkedList();				// destructor
	bool empty() const;			// is list empty?
	E& front();					// return front element
	void addFront(const E& e);		// add to front of list
	void removeFront();			// remove front item list
	int size() const;					// list size
private:
	SNode<E>* head;				// head of the list
	int     n;							// number of items
};

template <typename E>
SLinkedList<E>::SLinkedList()			// constructor
	: head(NULL), n(0) { }

template <typename E>
bool SLinkedList<E>::empty() const		// is list empty?
{
	return head == NULL; // can also use return (n == 0);
}

template <typename E>
E& SLinkedList<E>::front() 		// return front element
{
	if (empty()) throw length_error("empty list");
	return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList()			// destructor
{
	while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {	// add to front of list
	SNode<E>* v = new SNode<E>;		// create new node
	v->elem = e;				// store data
	v->next = head;				// head now follows v
	head = v;				// v is now the head
	n++;
}

template <typename E>
void SLinkedList<E>::removeFront() {		// remove front item
	if (empty()) throw length_error("empty list");
	SNode<E>* old = head;			// save current head
	head = old->next;			// skip over old head
	delete old;				// delete the old head
	n--;
}

template <typename E>
int SLinkedList<E>::size() const {				// list size
	return n;
}
