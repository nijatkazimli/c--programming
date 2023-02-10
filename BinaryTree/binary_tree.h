#pragma once


#include "binary_tree_node.h"


class BinaryTree {
private:
	BinaryTreeNode* root;
public:
	BinaryTree(BinaryTreeNode*);
	BinaryTree();
	BinaryTree(int*, int);
	~BinaryTree();
	void print() const;






};