#include "binary_tree_node.h"

class BinaryTreeNodeWithInOrder : public BinaryTreeNode {
	

public:
	BinaryTreeNodeWithInOrder(int value, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr);
	virtual ~BinaryTreeNodeWithInOrder();
	void printAll() const override;

};