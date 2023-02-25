#pragma once

#ifndef BinarySearchTree_H
#define BinarySearchTree_H

template <class T>
class BinarySearchTree
{
private:
	struct Node {
	public:
		Node(T data, Node* left = nullptr, Node* right = nullptr) :
			m_data(data),
			m_left(left),
			m_right(right) {};

	public:
		T m_data;
		Node* m_left;
		Node* m_right;
	};

public:
	BinarySearchTree<T>();
	BinarySearchTree<T>(Node*);
	~BinarySearchTree<T>();

public:
	void insert(T);
	Node* remove(T);
	Node* getRoot();
	Node* search(T);
	int getHeight(Node*);  // the height of the root node or the depth of the deepest node
	int getDepthOfNode(Node*);  // number of edges from the root to the node
	int coundOfNodes(Node*);
	void printLevel(Node*, int);

	void printLevelOrder(Node*);
	void printInorder(Node*);
	void printPreorder(Node*);
	void printPostorder(Node*);

	bool isFull(Node*); // every parent node has either two or no children
	bool isPerfect(Node*, int, int); // every parent node has two children
	bool isPerfect(Node*);

// helper functions
private:
	void recursiveDestruction(Node*);

private:
	Node* root;
};

#endif // !BinarySearchTree_H