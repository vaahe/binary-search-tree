#include <iostream>
#include "BinarySearchTree.hpp"


int main() {
	BinarySearchTree<int>* tree = new BinarySearchTree<int>();

	tree->insert(10);
	tree->insert(15);
	tree->insert(20);
	tree->insert(6);
	tree->insert(13);
	tree->insert(17);
	tree->insert(24);


	tree->remove(10);
	tree->printLevelOrder(tree->getRoot());
	std::cout << std::endl;

	std::cout << "Inorder: ";
	tree->printInorder(tree->getRoot());
	std::cout << std::endl;

	std::cout << "Postorder: ";
	tree->printPostorder(tree->getRoot());
	std::cout << std::endl;

	std::cout << "Preorder: ";
	tree->printPreorder(tree->getRoot());
	std::cout << std::endl;

	tree->~BinarySearchTree();

	return 0;
}