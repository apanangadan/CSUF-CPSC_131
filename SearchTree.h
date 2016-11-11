// code from
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//

#pragma once
#include "LinkedBinaryTree.h"

template <typename K, typename V>
class Entry {
public:
	typedef K Key;
	typedef V Value;
	Entry(const Key &k = Key(), const Value &v = Value())
		: _key(k), _value(v) {}
	const Key& key() const { return _key; }
	const Value& value() const { return _value; }
	void setKey(const Key& k) { _key = k; }
	void setValue(const Value& v) { _value = v; }
private:
	Key _key;
	Value _value;
};

template <typename E>
class SearchTree {					// a binary search tree
public: 						// public types
	typedef typename E::Key K;				// a key
	typedef typename E::Value V;			// a value
	// class Iterator;					// an iterator/position
public:						// public functions
	SearchTree();					// constructor
	int size() const; 					// number of entries
	bool empty() const;					// is the tree empty?
	Position<E> find(const K& k);				// find entry with key k
	Position<E> insert(const K& k, const V& x);		// insert (k,x)
	void erase(const K& k);	// remove key k entry
	//void erase(const Iterator& p);			// remove entry at p
	// Iterator begin();					// iterator to first entry
	//Iterator end();					// iterator to end entry
	void printInorder() const;
protected:						// local utilities
	// BinaryTree<E> BinaryTree;			// linked binary tree
	//typedef typename BinaryTree::Position TPos;		// position in the tree
	Position<E> root() const;					// get virtual root
	Position<E> finder(const K& k, const Position<E>& v);		// find utility
	Position<E> inserter(const K& k, const V& x);		// insert utility
	void inorder(Position<E>& v) const; // inorder print utility
	Position<E> eraser(Position<E>& v);				// erase utility
	// Position restructure(const TPos& v);	// restructure
private: 						// member data
	LinkedBinaryTree<E> T;					// the binary tree
	int n;						// number of entries
public:
	// ...insert Iterator class declaration here
};


template <typename E>					// constructor
SearchTree<E>::SearchTree() : T(), n(0)
{
	T.addRoot();
}

template <typename E>					// get virtual root
Position<E> SearchTree<E>::root() const
{
	return T.root();
}

template <typename E>
int SearchTree<E>::size() const			// number of nodes
{
	return n;
}

template <typename E>
bool SearchTree<E>::empty() const			// is tree empty?
{
	return size() == 0;
}

template <typename E>
void SearchTree<E>::printInorder() const			// is tree empty?
{
	cout << "Keys in order: ";
	inorder(root());
	cout << endl;
}

template <typename E>
void SearchTree<E>::inorder(Position<E>& v) const			// is tree empty?
{
	if (v.isExternal()) return;
	inorder(v.left());
	cout << (*v).key() << ", ";
	inorder(v.right());
}

template <typename E>					// find utility
Position<E> SearchTree<E>::finder(const K& k, const Position<E>& v) {
	if (v.isExternal()) return v;			// key not found
	if (k < (*v).key()) return finder(k, v.left());	// search left subtree
	else if ((*v).key() < k) return finder(k, v.right());	// search right subtree
	else return v;					// found it here
}

template <typename E>					// find entry with key k
Position<E> SearchTree<E>::find(const K& k) {
	return finder(k, root());				// search from root
}

template <typename E>					// insert utility
Position<E> SearchTree<E>::inserter(const K& k, const V& x) {
	Position<E> v = finder(k, root());				// search from root
	if (!v.isExternal()) {			// key already exists?
		(*v).setValue(x);			// update value
	}
	else {
		T.expandExternal(v);		// add new internal node
		(*v).setKey(k);
		(*v).setValue(x);			// set entry
		n++;						// one more entry
	}
	return v;						// return insert position
}

template <typename E>					// insert (k,x)
Position<E> SearchTree<E>::insert(const K& k, const V& x)
{
	return inserter(k, x);
}

template <typename E>					// remove utility
Position<E> SearchTree<E>::eraser(Position<E>& v) {
	Position<E> w;
	if (v.left().isExternal()) 
		w = v.left();		// remove from left
	else if (v.right().isExternal()) 
		w = v.right();	// remove from right
	else {						// both internal?
		w = v.right();					// go to right subtree
		do { w = w.left(); } while (!w.isExternal());	// get leftmost node
		Position<E> u = w.parent();
		(*v).setKey((*u).key());
		(*v).setValue((*u).value());	// copy w's parent to v
	}
	n--;						// one less entry
	return T.removeAboveExternal(w);			// remove w and parent
}

template <typename E>					// remove key k entry
void SearchTree<E>::erase(const K& k) {
	Position<E> v = finder(k, root());	// search from virtual root
	if (v.isExternal())					// not found?
		throw out_of_range("Erase of nonexistent key");
	eraser(v);						// remove it
}
