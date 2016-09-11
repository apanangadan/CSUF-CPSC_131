// Templated singly linked list class with iterators using code from
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>

using namespace std;

template <typename E> class SNodeList;	// forward declaration to be used when declaring SNode

template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E> *next;				// next item in the list
	friend class SNodeList<E>;		// provide SLinkedList access
};

template <typename E>
class SNodeList {				// a singly linked list
public:
	// Iterator is a nested class within SNodeList<E>
	class Iterator {				// an iterator for the list
	public:
		E& get() {		// reference to the element
			return v->elem;
		}
		E& operator*() {		// reference to the element
			return v->elem;
		}
		bool operator==(const Iterator& p) const {	// compare positions
			return v == p.v;
		}
		bool operator!=(const Iterator& p) const {
			return v != p.v;
		}
		Iterator& operator++() {		// move to next position
			v = v->next; return *this;
		}
		friend class SNodeList;			// give NodeList access
	private:
		SNode<E>* v;					// pointer to the node
		Iterator(SNode<E>* u) {		// constructor from SNode*
			v = u;
		}
	};

public:
	SNodeList();				// empty list constructor
	~SNodeList();				// destructor
	bool empty() const;			// is list empty?
	E& front();					// return front element
	void addFront(const E& e);		// add to front of list
	void removeFront();			// remove front item list
	int size() const;					// list size
	Iterator begin() const {		// beginning position is first item
		return Iterator(head);
	}
	Iterator end() const {		// end position is just beyond last
		return Iterator(NULL);
	}

private:
	SNode<E>* head;				// head of the list
	int     n;							// number of items
};

template <typename E>
SNodeList<E>::SNodeList()			// constructor
	: head(NULL), n(0) { }

template <typename E>
bool SNodeList<E>::empty() const		// is list empty?
{
	return head == NULL; // can also use return (n == 0);
}

template <typename E>
E& SNodeList<E>::front() 		// return front element
{
	if (empty()) throw length_error("empty list");
	return head->elem;
}

template <typename E>
SNodeList<E>::~SNodeList()			// destructor
{
	while (!empty()) removeFront();
}

template <typename E>
void SNodeList<E>::addFront(const E& e) {	// add to front of list
	SNode<E>* v = new SNode<E>;		// create new node
	v->elem = e;				// store data
	v->next = head;				// head now follows v
	head = v;				// v is now the head
	n++;
}

template <typename E>
void SNodeList<E>::removeFront() {		// remove front item
	if (empty()) throw length_error("empty list");
	SNode<E>* old = head;			// save current head
	head = old->next;			// skip over old head
	delete old;				// delete the old head
	n--;
}

template <typename E>
int SNodeList<E>::size() const {				// list size
	return n;
}