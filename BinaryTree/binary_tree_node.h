#pragma once

#include <ostream>

class BinaryTreeNode {
public:

	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	BinaryTreeNode(int, BinaryTreeNode* = nullptr, BinaryTreeNode* = nullptr);
	void print() const;
	virtual void printAll() const;
	virtual ~BinaryTreeNode();





};