#include <iostream>
#include <exception>

#include "binary_tree.h"
#include "binary_tree_node_with_in_order.h"

BinaryTree::BinaryTree(BinaryTreeNode* root) : root(root)
{

}

BinaryTree::BinaryTree() : root(nullptr)
{
}

BinaryTree::BinaryTree(int* arr, int size) : root(nullptr)
{
	//if (size != 0 && size != 1 && size != 3 && size != 7 && size != 15 && size != 31 && size != 63) {
	//	throw std::logic_error("Error: number of values passed to tree constructor is incorrect");
	//}

	int i = 1;

	while (size != i) {

		
		
		i = i * 2 + 1;
		if (size != i)
			throw "Error: number of values passed to tree constructor is incorrect";
		
	}
	
}

BinaryTree::~BinaryTree()
{
	delete root;
}

void BinaryTree::print() const
{
	if(root)
		root->printAll();
}
