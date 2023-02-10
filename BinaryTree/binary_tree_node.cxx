#include <iostream>
#include "binary_tree_node.h"

BinaryTreeNode::BinaryTreeNode(int value, BinaryTreeNode* left, BinaryTreeNode* right)  : value(value), left(left), right(right)
{
}


void BinaryTreeNode::print() const
{
	
	std::cout << value;
}

void BinaryTreeNode::printAll() const
{
	this->print();
	std::cout << " ";
	if(left)
		left->printAll();
	if (right)
		right->printAll();
		
	

}

BinaryTreeNode::~BinaryTreeNode()
{
	delete left;
	delete right;
}
