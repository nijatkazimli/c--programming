#include <iostream>
#include <exception>

#include "binary_tree_node.h"
#include "binary_tree.h"
#include "binary_tree_node_with_in_order.h"

int main()
{
	// PART 1 (1 point) - implement BinaryTreeNode class

	auto node_with_1 = new BinaryTreeNode(1);
	auto node_with_5 = new BinaryTreeNode(5);
	auto node_with_3 = new BinaryTreeNode(3);
	auto node_with_7_and_left_child_5 = new BinaryTreeNode(7, node_with_5);
	auto node_with_9_and_children_1_and_7 = new BinaryTreeNode(9, node_with_1, node_with_7_and_left_child_5);
	delete node_with_3;
	delete node_with_9_and_children_1_and_7;
	// expected output: (none)

	// PART 2 (1 point) - add print() method to print value of BinaryTreeNode (only value of given node, not its children)

	auto node_with_2 = new BinaryTreeNode(2);
	auto node_with_6_and_right_child_2 = new BinaryTreeNode(6, nullptr, node_with_2);
	auto node_with_7_and_left_child_6 = new BinaryTreeNode(7, node_with_6_and_right_child_2);
	node_with_7_and_left_child_6->print();
	std::cout << std::endl;
	delete node_with_7_and_left_child_6;
	// expected output:
	// 7

	// PART 3 (1 point) - add printAll() to print value of BinaryTreeNode and all its children (in pre-order)

	node_with_1 = new BinaryTreeNode(1);
	auto node_with_2_and_right_child_1 = new BinaryTreeNode(2, nullptr, node_with_1);
	auto node_with_4_and_left_child_2 = new BinaryTreeNode(4, node_with_2_and_right_child_1);
	node_with_4_and_left_child_2->printAll();
	std::cout << std::endl;
	delete node_with_4_and_left_child_2;

	// expected output:
	// 7
	// 4 2 1 

	// PART 4 (1 point) - implement BinaryTree class

	auto tree_1 = new BinaryTree();
	tree_1->print();

	node_with_1 = new BinaryTreeNode(1);
	node_with_2_and_right_child_1 = new BinaryTreeNode(2, nullptr, node_with_1);
	node_with_4_and_left_child_2 = new BinaryTreeNode(4, node_with_2_and_right_child_1);
	auto tree_2 = new BinaryTree(node_with_4_and_left_child_2);
	tree_2->print();
	delete tree_1;
	delete tree_2;
	// expected output:
	// 7
	// 4 2 1
	// 4 2 1 

	// PART 5 (1 point) - implement BinaryTreeNodeWithInOrder class

	node_with_1 = new BinaryTreeNodeWithInOrder(1);
	node_with_2_and_right_child_1 = new BinaryTreeNodeWithInOrder(2, nullptr, node_with_1);
	auto node_with_4 = new BinaryTreeNodeWithInOrder(4);
	auto node_with_5_and_children_2_and_4 = new BinaryTreeNodeWithInOrder(5, node_with_2_and_right_child_1, node_with_4);

	auto* tree_3 = new BinaryTree(node_with_5_and_children_2_and_4);
	tree_3->print();
	delete tree_3;
	// expected output):
	// 7
	// 4 2 1
	// 4 2 1 
	// 2 1 5 4

	// PART 6 (1 point) - implement BinaryTreeNodeWithInOrder extra constructor
	// Add try - catch construct here

	// correct input:
	int values_1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	const auto values_count_1 = sizeof(values_1) / sizeof(values_1[0]);
	try {
		auto* tree_4 = new BinaryTree(values_1, values_count_1);
		tree_4->print();
		delete tree_4;
		// incorrect input:
		int values_2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
		const auto values_count_2 = sizeof(values_2) / sizeof(values_2[0]);
		tree_4 = new BinaryTree(values_2, values_count_2);

		tree_4->print();
		delete tree_4;
	}
	catch (char *exp) {
		std::cout << exp;
		
	}
	
	// expected output:
	// 7
	// 4 2 1
	// 4 2 1 
	// 2 1 5 4
	// Error: number of values passed to tree constructor is incorrect.


	// PART 7 (2 points) - implement BinaryTreeNodeWithInOrder extra constructor
/*
	int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	const auto values_count = sizeof(values) / sizeof(values[0]);
	auto *tree_4 = new BinaryTree(values, values_count);
	tree_4->print();
	delete tree_4;
	// expected output:
	// 7
	// 4 2 1
	// 4 2 1 
	// 2 1 5 4
	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
	// Error: number of values passed to tree constructor is incorrect.
	// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15	
*/	
	return 0;	
}
