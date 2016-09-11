// Templated doubly linked list class with iterators using code from
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//
#pragma once

#include <stdexcept>

////////// To implement the NodeList class with iterators //////////////////
//template <typename E>			// list base element type
//class NodeList {				// node-based list
//public:
//	NodeList();					// default constructor
//	int size() const;				// list size
//	bool empty() const;				// is the list empty?
//	Iterator begin() const;			// beginning position
//	Iterator end() const;			// (just beyond) last position
//	void insertFront(const E& e);		// insert at front
//	void insertBack(const E& e);		// insert at rear
//	void insert(const Iterator& p, const E& e); // insert e before p
//	void eraseFront();				// remove first
//	void eraseBack();				// remove last
//	void erase(const Iterator& p);		// remove p
//										// housekeeping functions omitted...
//private:					// data members
//	int     n;					// number of items
//	Node*   header;				// head-of-list sentinel
//	Node*   trailer;				// tail-of-list sentinel
//};

using namespace std;

template <typename E> class NodeList;	// forward declaration to be used when declaring DNode

template <typename E>
class DNode {					            // doubly linked list node
private:
	E elem;					               // node element value
	DNode<E> *prev;				         // previous node in the list
	DNode<E> *next;				         // next node in the list
	friend class NodeList<E>;		   // provide SLinkedList access
};



template <typename E>			// list base element type
class NodeList {				// node-based list

public:
	// Iterator is a nested class within NodeList<E>
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
		Iterator& operator++()	{		// move to next position
			v = v->next; return *this;
		}
		Iterator& operator--()	{		// move to previous position
			v = v->prev; return *this;
		}
		friend class NodeList;			// give NodeList access
	private:
		DNode<E>* v;					// pointer to the node
		Iterator(DNode<E>* u)	{		// constructor from DNode*
			v = u;
		}
	};

public:
	NodeList()	{				// default constructor
		n = 0;							// initially empty
		header = new DNode<E>;              // create sentinels
		trailer = new DNode<E>;
		header->next = trailer;             // have them point to each other
		trailer->prev = header;
	}

	int size() const {				// list size
		return n;
	}

	bool empty() const	{			// is the list empty?
		return (n == 0);
	}

	Iterator begin() const	{		// beginning position is first item
		return Iterator(header->next);
	}

	Iterator end() const	{		// end position is just beyond last
		return Iterator(trailer);
	}

	void insertFront(const E& e) {	// insert at front
		insert(begin(), e);
	}

	void insertBack(const E& e) {		// insert at rear
		insert(end(), e);
	}

	void insert(const Iterator& p, const E& e) {// insert e before p
		DNode<E>* w = p.v;				// p's node
		DNode<E>* u = w->prev;				// p's predecessor
		DNode<E>* v = new DNode<E>;				// new node to insert
		v->elem = e;
		v->next = w;  w->prev = v;			// link in v before w
		v->prev = u;  u->next = v;			// link in v after u
		n++;
	}

	void eraseFront()	{			// remove first
		erase(begin());
	}

	void eraseBack()	{			// remove last
		erase(--end());
	}

	void erase(const Iterator& p)	{	// remove p
		if (empty()) throw length_error("empty list");
		DNode<E>* v = p.v;				// node to remove
		DNode<E>* w = v->next;				// successor
		DNode<E>* u = v->prev;				// predecessor
		u->next = w;  w->prev = u;			// unlink p
		delete v;					// delete this node
		n--;					// one fewer element
	}

	~NodeList() {	      // destructor
		while (!empty()) eraseFront();     // remove all but sentinels
		delete header;				            // remove the sentinels
		delete trailer;
	}
private:					// data members
	int     n;					// number of items
	DNode<E>*   header;				// head-of-list sentinel
	DNode<E>*   trailer;				// tail-of-list sentinel
};
