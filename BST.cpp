#include <iostream>
#include "BST.h"
using namespace std;

template <class T>
BST<T>::BST() {
	root = nullptr;
}
template <class T>
void BST<T>::deleteBST(Node *currNode) {
	if (currNode->left) {
		deleteBST(currNode->left);
	}
	if (currNode->right) {
		deleteBST(currNode->right);
	}

	delete currNode;
}
template <class T>
BST<T>::~BST()
{
	deleteBST(root);
}
template <class T>
void BST<T>::insertNode(Node *&currNode, Node *&newNode) {
	if (currNode == nullptr)
		currNode = newNode;
	else if (newNode->value < currNode->value)
		insertNode(currNode->left, newNode);
	else
		insertNode(currNode->right, newNode);
}
template <class T>
void BST<T>::insert(T value) {
	Node *newNode = new Node;
	newNode->value = value;
	newNode->left = newNode->right = nullptr;

	insertNode(root, newNode);
}
template <class T>
bool BST<T>::search(T value) {
	// use the recursive search method
	return searchNode(root, value);


	// not using below code
	Node *currNode = root;

	while (currNode) {
		if (currNode->value == value)
			return true;

		if (value < currNode->value)
			currNode = currNode->left;
		else
			currNode = currNode->right;
	}
	return false;
}
template <class T>
bool BST<T>::searchNode(Node *currNode, T value) {
	if (currNode == nullptr)
		return false;
	if (currNode->value == value)
		return true;

	if (value < currNode->value)
		return searchNode(currNode->left, value);
	else
		return searchNode(currNode->right, value);
}
template <class T>
void BST<T>::remove(T value) {
	deleteNode(root, value);
}
template <class T>
void BST<T>::deleteNode(Node *&currNode, T value) {
	if (value < currNode->value)
		deleteNode(currNode->left, value);
	else if (value > currNode->value)
		deleteNode(currNode->right, value);
	else
		makeDeletion(currNode);
}
template <class T>
void BST<T>::makeDeletion(Node *&currNode) {
	Node *tempNode = nullptr;

	if (currNode == nullptr)
		return;

	if (currNode->right == nullptr) {
		tempNode = currNode;
		currNode = currNode->left;
		delete tempNode;
	}
	else if (currNode->left == nullptr) {
		tempNode = currNode;
		currNode = currNode->right;
		delete tempNode;
	}
	else {
		/* attach left subtree in right subtree */
		tempNode = currNode->right;
		while (tempNode->left != nullptr)
			tempNode = tempNode->left;

		tempNode->left = currNode->left;

		/* delete node */
		tempNode = currNode;
		currNode = currNode->right;
		delete tempNode;
	}
}

template <class T>
int BST<T>::countNode (Node *currNode)
{
	if (currNode == nullptr )
		return 0;

	else if (currNode->left == nullptr && currNode->right == nullptr)
		return 1;
	else
		return (1 + (countNode(currNode->left)+countNode(currNode->right)));
}

template <class T>
int BST<T>::countLeaf (Node *currNode)
{
	if (currNode == nullptr )
		return 0;

	else if (currNode->left == nullptr && currNode->right == nullptr)
		return 1;
	else
		return countNode(currNode->left)+countNode(currNode->right);
}

template <class T>
int BST<T>::height (Node *currNode)
{
	if (currNode == nullptr )
		{return -1;}
	int hl = height(currNode->left);
	int hr = height(currNode->right);

	return 1 + max (height(currNode->left),height(currNode->right));
}

