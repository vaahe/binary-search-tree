#include "binarySearchTree.h"
#include <iostream>

template <class T>
BinarySearchTree<T>::BinarySearchTree() {
	root = nullptr;
}


template <class T>
BinarySearchTree<T>::BinarySearchTree(Node* node) {
	root = new Node(node->m_data, node->m_left, node->m_right);
}


template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
	recursiveDestruction(root);
}


template <class T>
void BinarySearchTree<T>::recursiveDestruction(Node* root) {
	if (root) {
		recursiveDestruction(root->m_left);
		recursiveDestruction(root->m_right);
		delete root;
	}
}


template <class T>
void BinarySearchTree<T>::insert(T data) {
	Node* newNode = new Node(data);

	if (root == nullptr) {
		root = newNode;
	}
	else {
		Node* current = root;
		Node* parent;

		while (true) {
			parent = current;

			if (data < current->m_data) {
				current = current->m_left;
				if (current == nullptr) {
					parent->m_left = newNode;
					return;
				}
			}
			else {
				current = current->m_right;
				if (current == nullptr) {
					parent->m_right = newNode;
					return;
				}
			}
		}
	}
}


template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::remove(T data) {
	if (root == nullptr) {
		return root;
	}

	if (root->m_data == data) {
		Node* current = root;

		if (root->m_left != nullptr && root->m_right != nullptr) {
			Node* tmp = root->m_right;

			while (tmp->m_left != nullptr) {
				tmp = tmp->m_left;
			}

			tmp->m_left = current->m_left;
			root = current->m_right;

			delete current;
			return current;
		}
		else if (root->m_left != nullptr && root->m_right == nullptr) {
			root = root->m_left;

			delete root;
			return root;
		}
		else if (root->m_left == nullptr) {
			root = root->m_left;

			delete current;
			return current;
		}
	}

	Node* current = root;
	Node* prev = current;

	while (current != nullptr) {
		if (data > current->m_data && current->m_right != nullptr) {
			prev = current;
			current = current->m_right;

			if (current->m_data == data) {
				if (current->m_left != nullptr && current->m_right != nullptr) {
					Node* ptr = current->m_right;
					prev->m_right = current->m_right;

					while (ptr->m_left != nullptr) {
						ptr = ptr->m_left;
					}

					ptr->m_left = current->m_left;

					delete current;
					return current;
				}
				else if (current->m_left != nullptr && current->m_right == nullptr) {
					prev->m_right = current->m_left;

					delete current;
					return current;
				}
				else if (current->m_left == nullptr) {
					prev->m_right = current->m_right;

					delete current;
					return current;
				}
			}
		}
		else if (data > current->m_data && current->m_right == nullptr) {
			return nullptr;
		}

		else if (data < current->m_data && current->m_left != nullptr) {
			prev = current;
			current = current->m_left;

			if (current->m_data == data) {
				if (current->m_left != nullptr && current->m_right != nullptr) {
					Node* tmp = current->m_right;
					prev->m_left = current->m_right;

					while (tmp->m_left != nullptr) {
						tmp = tmp->m_left;
					}

					tmp->m_left = current->m_left;

					delete current;
					return current;
				}
				else if (current->m_left != nullptr && current->m_right == nullptr) {
					prev->m_left = current->m_left;

					delete current;
					return current;
				}
				else if (current->m_left == nullptr) {
					prev->m_left = current->m_right;

					delete current;
					return current;
				}
			}
		}
		else if (data < current->m_data && current->m_left == nullptr) {
			return nullptr;
		}
	}
}


template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::search(T key) {
	if (root == nullptr) {
		return nullptr;
	}

	Node* tmp = root;

	while (tmp) {
		if (key == tmp->m_data) {
			return tmp;
		}
		else if (key < tmp->m_data) {
			tmp = tmp->m_left;
		}
		else if (key > tmp->m_data) {
			tmp = tmp->m_right;
		}
	}

	return nullptr;
}


template <class T>
typename BinarySearchTree<T>::Node* BinarySearchTree<T>::getRoot() {
	return root;
}


template <class T>
int BinarySearchTree<T>::getHeight(Node* root) {
	if (root == nullptr) {
		return 0;
	}
	else {
		int lHeight = getHeight(root->m_left);
		int rHeight = getHeight(root->m_right);

		return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
	}
}


template <class T>
int BinarySearchTree<T>::getDepthOfNode(Node* root) {
	int depth = 0;

	while (root != nullptr) {
		depth++;
		root = root->m_left;
	}

	return depth;
}


template <class T>
int BinarySearchTree<T>::coundOfNodes(Node* root) {
	if (root == nullptr) {
		return 0;
	}

	return (1 + coundOfNodes(root->m_left) + coundOfNodes(root->m_right));
}


template <class T>
void BinarySearchTree<T>::printLevel(Node* root, int level) {
	if (root == nullptr) {
		return;
	}
	
	if (level == 1) {
		std::cout << root->m_data << " ";
	}
	else if (level > 1) {
		printLevel(root->m_left, level - 1);
		printLevel(root->m_right, level - 1);
	}
}


template <class T>
void BinarySearchTree<T>::printLevelOrder(Node* root) {
	if (root == nullptr) {
		return;
	}

	for (int i = 1; i <= getHeight(root); ++i) {
		std::cout << "Level " << i << ": ";
		printLevel(root, i);
		std::cout << std::endl;
	}
}


template <class T>
void BinarySearchTree<T>::printInorder(Node* root) {
	if (root == nullptr) {
		return;
	}

	printInorder(root->m_left);
	std::cout << root->m_data << " ";
	printInorder(root->m_right);
}


template <class T>
void BinarySearchTree<T>::printPostorder(Node* root) {
	if (root == nullptr) {
		return;
	}

	printPostorder(root->m_left);
	printPostorder(root->m_right);
	std::cout << root->m_data << " ";
}


template <class T>
void BinarySearchTree<T>::printPreorder(Node* root) {
	if (root == nullptr) {
		return;
	}

	std::cout << root->m_data << " ";
	printPreorder(root->m_left);
	printPreorder(root->m_right);
}


template <class T>
bool BinarySearchTree<T>::isFull(Node* root) {
	if (root == nullptr) {
		return true;
	}

	if (root->m_left == nullptr && root->m_right == nullptr) {
		return true;
	}

	if (root->m_left && root->m_right) {
		return (isFull(root->m_left) && isFull(root->m_right));
	}

	return false;
}


template <class T>
bool BinarySearchTree<T>::isPerfect(Node* root, int depth, int level) {
	if (root == nullptr) {
		return true;
	}

	if (root->m_left == nullptr && root->m_right == nullptr) {
		return (depth == level + 1);
	}

	if (root->m_left == nullptr || root->m_right == nullptr) {
		return false;
	}

	return isPerfect(root->m_left, depth, level + 1) && isPerfect(root->m_right, depth, level + 1);
}


template <class T>
bool BinarySearchTree<T>::isPerfect(Node* root) {
	int depth = getDepthOfNode(root);

	return isPerfect(root, depth, 0);
}