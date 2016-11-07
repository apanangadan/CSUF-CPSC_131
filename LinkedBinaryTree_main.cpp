#include <iostream>
#include <string>
#include "LinkedBinaryTree.h"

using namespace std;

int main() {

	/* create the following binary tree:
	    9
	   / \
	  7   11
	 /  \
	 3    8
	/ \
	2   5
	*/

	LinkedBinaryTree<int> tree;
	tree.addRoot(9);
	tree.addLeftLeaf(tree.root(), 7);
	tree.addRightLeaf(tree.root(), 11);
	tree.addLeftLeaf(tree.root().left(), 3);
	tree.addLeftLeaf(tree.root().left().left(), 2);
	tree.addRightLeaf(tree.root().left().left(), 5);
	tree.addRightLeaf(tree.root().left(), 8);

	cout << "Preorder:" << endl;
	tree.preorderPrint();

	cout << endl << "Inorder:" << endl;
	tree.inorderPrint();

	cout << endl << "Postorder:" << endl;
	tree.postorderPrint();

	//system("pause");
	return 0;
}
