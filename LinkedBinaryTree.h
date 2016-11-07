// code from
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//

#pragma once

#include <stdexcept>

using namespace std;

template <typename E> class LinkedBinaryTree; // forward declaration to be used when declaring TNode
template <typename E> class Position; // forward declaration to be used when declaring TNode

template <typename E>
class TNode { // a node of the tree
private:
	E		elem;					// element value
	TNode<E> *par;					// parent
	TNode<E> *left;					// left child
	TNode<E> *right;				// right child
	TNode<E>() : elem(), par(NULL), left(NULL), right(NULL) { } // default constructor
	// Node(E &e) : elem(e), par(NULL), left(NULL), right(NULL) { } // constructor
	friend class LinkedBinaryTree<E>; // provide LinkedBinaryTree access
	friend class Position<E>;		// provide Position access
};


template <typename E>
class Position {					// position in the tree
private:
	TNode<E> *v;						// pointer to the node
public:
	Position(TNode<E>* _v = NULL) : v(_v) { }		// constructor
	E& operator*()					// get element
	{
		return v->elem;
	}
	E& operator*() const                   		// get const element
	{
      		return v->elem;
   	}

	Position left() const				// get left child
	{
		return Position(v->left);
	}
	Position right() const				// get right child
	{
		return Position(v->right);
	}
	Position parent() const				// get parent
	{
		return Position(v->par);
	}
	bool isRoot() const				// root of the tree?
	{
		return (v->par == NULL);
	}
	bool isExternal() const				// an external node?
	{
		return v->left == NULL && v->right == NULL;
	}
	friend class LinkedBinaryTree<E>;			// give tree access
};


template <typename E>					// base element type
class LinkedBinaryTree {
protected:
	// insert Node declaration here...
public:
	// insert Position declaration here...
public:
	LinkedBinaryTree();					// constructor
	int size() const;					// number of nodes
	bool empty() const;					// is tree empty?
	Position<E> root() const;				// get the root
	void addRoot(const E& e = E());					// add root to empty tree
	void addLeftLeaf(const Position<E>& p, const E& e);		// expand external node
	void addRightLeaf(const Position<E>& p, const E& e);		// expand external node
	void preorderPrint() const;	// print nodes in preorder 
	void inorderPrint() const;	// print nodes in inorder 
	void postorderPrint() const;	// print nodes in postorder 
	void expandExternal(const Position<E>& p);		// expand external node
	Position<E> removeAboveExternal(const Position<E>& p);	// remove p and parent
							
	// housekeeping functions such as copy constructor omitted...
private:
	void preorder(TNode<E>* v) const;	// preorder utility
	void inorder(TNode<E>* v) const;	// inorder utility
	void postorder(TNode<E>* v) const;	// postorder utility
	TNode<E>* _root;					// pointer to the root
	int n;						// number of nodes
};

template <typename E>
LinkedBinaryTree<E>::LinkedBinaryTree()			// constructor
	: _root(NULL), n(0) { }

template <typename E>
int LinkedBinaryTree<E>::size() const			// number of nodes
{
	return n;
}

template <typename E>
bool LinkedBinaryTree<E>::empty() const			// is tree empty?
{
	return size() == 0;
}

template <typename E>
Position<E> LinkedBinaryTree<E>::root() const // get the root
{
	return Position<E>(_root);
}

template <typename E>
void LinkedBinaryTree<E>::addRoot(const E& e)			// add root to empty tree
{
	_root = new TNode<E>;
	_root->elem = e;
	n = 1;
}

// expand external node
template <typename E>
void LinkedBinaryTree<E>::addLeftLeaf(const Position<E>& p, const E& e) {
	TNode<E>* v = p.v;					// p's node
	v->left = new TNode<E>;				// add a new left child
	v->left->elem = e;					// v is its parent
	v->left->par = v;					// v is its parent
	n++;								// one more node
}

// expand external node
template <typename E>
void LinkedBinaryTree<E>::addRightLeaf(const Position<E>& p, const E& e) {
	TNode<E>* v = p.v;					// p's node
	v->right = new TNode<E>;				// add a new left child
	v->right->elem = e;					// v is its parent
	v->right->par = v;					// v is its parent
	n++;								// one more node
}

template <typename E>
void LinkedBinaryTree<E>::preorderPrint() const {
	preorder(_root);
}

template <typename E>
void LinkedBinaryTree<E>::preorder(TNode<E> *v) const {
	if (v == NULL) return;
	cout << v->elem << endl;
	preorder(v->left);
	preorder(v->right);
}

template <typename E>
void LinkedBinaryTree<E>::inorderPrint() const {
	inorder(_root);
}

template <typename E>
void LinkedBinaryTree<E>::inorder(TNode<E> *v) const {
	if (v == NULL) return;
	inorder(v->left);
	cout << v->elem << endl;
	inorder(v->right);
}

template <typename E>
void LinkedBinaryTree<E>::postorderPrint() const {
	postorder(_root);
}

template <typename E>
void LinkedBinaryTree<E>::postorder(TNode<E> *v) const {
	if (v == NULL) return;
	postorder(v->left);
	postorder(v->right);
	cout << v->elem << endl;
}

// expand external node
template <typename E>
void LinkedBinaryTree<E>::expandExternal(const Position<E>& p) {
	TNode<E>* v = p.v;					// p's node
	v->left = new TNode<E>;					// add a new left child
	v->left->par = v;					// v is its parent
	v->right = new TNode<E>;				// and a new right child
	v->right->par = v;					// v is its parent
	n += 2;						// two more nodes
}


// remove p and parent
template <typename E>
Position<E> LinkedBinaryTree<E>::removeAboveExternal(const Position<E>& p) {
	TNode<E>* w = p.v;
	TNode<E>* v = w->par;			// get p's node and parent
	TNode<E>* sib = (w == v->left ? v->right : v->left);
	if (v == _root) {					// child of root?
		_root = sib;					// ...make sibling root
		sib->par = NULL;
	}
	else {
		TNode<E>* gpar = v->par;				// w's grandparent
		if (v == gpar->left) gpar->left = sib; 		// replace parent by sib
		else gpar->right = sib;
		sib->par = gpar;
	}
	delete w; 
	delete v;					// delete removed nodes
	n -= 2;						// two fewer nodes
	return Position<E>(sib);
}
