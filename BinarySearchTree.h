#pragma once
#include	<iostream>

using namespace std;

template<typename K, typename V>
struct	Node
{
	Node() : parent_(0), left_(0), right_(0) { }
	V	operator*()	{ return(value_); }
	bool IsRoot() const { return(parent_ == NULL); }
	bool IsExternal() const { return((left_ == NULL) && (right_ == NULL)); }
	void	Show(ostream& stream);

	K		key_;
	Node*	left_;
	Node*	parent_;
	Node*	right_;
	V		value_;
};

template<typename K, typename V>
class	BinarySearchTree
{
	public:
		class	Iterator
		{
			public:
				Iterator() { }
				Iterator(Node<K, V>* node) : node_(node) { }
				const Node<K, V>& operator*() const { return(*node_); };
				Node<K, V>& operator*() { return(*node_); };

				bool	operator==(const Iterator& p) const
				{ return(node_ == p.node_); }

				bool	operator!=(const Iterator& p) const
				{ return(node_ != p.node_); }

				Iterator& operator++();

			private:
				Node<K, V>*		node_;
				friend class BinarySearchTree;
		};

		BinarySearchTree();
		Iterator	Find(const K& key);
		Iterator	Insert(const K& key, const V& value);
		bool		Erase(const K& key);
		void		Erase(const Iterator& i);
		void		Show(ostream& stream);

		int			Size() const;
		bool		Empty() const;
		Iterator	Begin();
		Iterator	End();

	private:
		Node<K, V>*	Eraser(Node<K, V>* node);
		void		ExpandExternal(Node<K, V>* node);
		Node<K, V>*	RemoveAboveExternal(Node<K, V>* node);
		Node<K, V>*	Finder(const K& key, Node<K, V>* node);
		Node<K, V>*	Inserter(const K& key, const V& value);
		Node<K, V>*	root_;
		int			size_;
		Node<K, V>*	superRoot_;
};

template<typename K, typename V>
BinarySearchTree<K, V>::BinarySearchTree()
{
	size_ = 0;

	//	Create the super root and make its left child the logical root of the tree.
	superRoot_ = new Node<K, V>;
	ExpandExternal(superRoot_);
	root_ = superRoot_->left_;
}

template<typename K, typename V>
typename BinarySearchTree<K, V>::Iterator	BinarySearchTree<K, V>::Find(const K& key)
{
	Node<K, V>*		node = Finder(key, root_);
	if (!node->IsExternal())	{
		return(Iterator(node));
	}
	else	{ // not found, return end iterator
		return(End());
	}
}

template<typename K, typename V>
Node<K, V>*	BinarySearchTree<K, V>::Finder(const K& key, Node<K, V>* node)
{
	if (node->IsExternal())	{
		return(node);
	}

	if (key == node->key_)	{
		return(node);
	}
	else if (key < node->key_)	{
		return(Finder(key, node->left_));
	}
	else {
		return(Finder(key, node->right_));
	}
}

template<typename K, typename V>
void	BinarySearchTree<K, V>::Show(ostream& stream)
{
	root_->Show(stream);
	return;
}

template<typename K, typename V>
void	Node<K, V>::Show(ostream& stream)
{
	if (!IsExternal())	{
		left_->Show(stream);
		stream << key_ << " " << value_ << endl;
		right_->Show(stream);
	}
	return;
}

template<typename K, typename V>
typename BinarySearchTree<K, V>::Iterator
	BinarySearchTree<K, V>::Insert(const K& key, const V& value)
{
	Node<K, V>*		node = Inserter(key, value);
	return(Iterator(node));
}

template<typename K, typename V>
Node<K, V>*	BinarySearchTree<K, V>::Inserter(const K& key, const V& value)
{
	Node<K, V>*		node = Finder(key,root_);
	while (!node->IsExternal()) {
		node = Finder(key, node->right_);
	}
	ExpandExternal(node);
	node->key_ = key;
	node->value_ = value;
	++size_;
	return(node);
}

template<typename K, typename V>
bool	BinarySearchTree<K, V>::Erase(const K& key)
{
	Node<K, V>*		node = Finder(key, root_);
	if (!node->IsExternal())	{
		Eraser(node);
		return(true);
	}
	else	{
		return(false);
	}
}

template<typename K, typename V>
void	BinarySearchTree<K, V>::Erase(const Iterator& i)
{
	Eraser(i.node_);
}

template<typename K, typename V>
Node<K, V>*	BinarySearchTree<K, V>::Eraser(Node<K, V>* node)
{
	Node<K, V>*		remove;
	//	Is the node's left child an external node?
	if (node->left_->IsExternal())	{
		remove = node->left_;
	}
	else if (node->right_->IsExternal()) {
		remove = node->right_;
	}
	else	{
		//	Both children are internal nodes. Find the node's logical successor by
		//	going down to the right child subtree and then all the way down to the
		//	bottom left corner of that subtree.
		remove = node->right_;
		do		{
			remove = remove->left_;
		} while (!remove->IsExternal());

		Node<K, V>*		removeParent = remove->parent_;
		node->key_ = removeParent->key_;
		node->value_ = removeParent->value_;
	}
	--size_;

	return(RemoveAboveExternal(remove));
}

template<typename K, typename V>
void	BinarySearchTree<K, V>::ExpandExternal(Node<K, V>* node)
{
	node->left_ = new Node<K, V>;
	node->left_->parent_ = node;

	node->right_ = new Node<K, V>;
	node->right_->parent_ = node;

	size_ += 2;
}

template<typename K, typename V>
Node<K, V>*	BinarySearchTree<K, V>::RemoveAboveExternal(Node<K, V>* node)
{
	Node<K, V>*	child = node;
	Node<K, V>*	parent = child->parent_;
	Node<K, V>*	sibling = (child == parent->left_ ? parent->right_ : parent->left_);

	if (parent == root_) {
		root_ = sibling;
		sibling->parent_ = NULL;
	}
	else	{
		Node<K, V>* grandParent = parent->parent_;

		if (parent == grandParent->left_)		{
			grandParent->left_ = sibling;
		}
		else	{
			grandParent->right_ = sibling;
		}
		sibling->parent_ = grandParent;
	}

	delete child;
	delete parent;
	size_ -= 2;
	return(sibling);
}

template<typename K, typename V>
int		BinarySearchTree<K, V>::Size() const
{
	return(size_);
}

template<typename K, typename V>
bool	BinarySearchTree<K, V>::Empty() const
{
	return(size_ == 0);
}

template<typename K, typename V>
typename BinarySearchTree<K, V>::Iterator	BinarySearchTree<K, V>::Begin()
{
	Node<K, V>*		node = root_;
	//	Travel down the left side of the tree to the lower-left external node.
	while (!node->IsExternal())	{
		node = node->left_;
	}
	//	Return an iterator to the lower-leftmost internal node.
	return(Iterator(node->parent_));
}

template<typename K, typename V>
typename BinarySearchTree<K, V>::Iterator	BinarySearchTree<K, V>::End()
{
	return(Iterator(superRoot_));
}

template<typename K, typename V>
typename BinarySearchTree<K, V>::Iterator& BinarySearchTree<K, V>::Iterator::operator++()
{
	//	Is there a right subtree?
	Node<K, V>*	next = node_->right_;
	if (!next->IsExternal())	{
		//	Yes, go down to its lowest node.
		do		{
			node_ = next;
			next = next->left_;
		} while (!next->IsExternal());
	}
	else 	{
		//	No, go up until we see the parent of a left subtree.
		next = node_->parent_;
		while (node_ == next->right_)		{
			node_ = next;
			next = next->parent_;
		}
		node_ = next;
	}
	return(*this);
}
