#pragma once
template <class T>
class BST
{
private:
	struct Node {
		int value;
		Node *left;
		Node *right;
	};
	Node *root;

	void insertNode(Node *&, Node *&);
	bool searchNode(Node *, T);
	void deleteNode(Node *&, T);
	void makeDeletion(Node *&);
	int countNode(Node *);
	int countLeaf(Node *);
	int height(Node *);

	void deleteBST(Node *);
public:
	BST();
	~BST();
	void insert(T value);
	bool search(T value);
	void remove(T value);
};
