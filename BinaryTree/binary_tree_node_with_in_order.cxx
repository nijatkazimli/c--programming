#include <iostream>
#include "binary_tree_node_with_in_order.h"

BinaryTreeNodeWithInOrder::BinaryTreeNodeWithInOrder(int value, BinaryTreeNode* left, BinaryTreeNode* right) : BinaryTreeNode(value, left, right)
{
	
}

BinaryTreeNodeWithInOrder::~BinaryTreeNodeWithInOrder()
{
}

void BinaryTreeNodeWithInOrder::printAll() const
{
	if (left)
		left->printAll();
	this->print();
	std::cout << " ";
	if (right)
		right->printAll();

}
