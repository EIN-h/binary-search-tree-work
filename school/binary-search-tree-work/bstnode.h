#include<iostream>

template<typename T>
class BSTNode {//binary search tree node
public:
	BSTNode(const T &k, BSTNode *left, BSTNode *right)
		: key(k), lchild(left), rchild(right) {};

	BSTNode(const T &k)
		: key(k), lchild(nullptr), rchild(nullptr) {};

	BSTNode(const BSTNode *bNode)
		: key(bNode->key), lchild(bNode->lchild), rchild(bNode->rchild) {};

	//private:
	T key;
	BSTNode *lchild;
	BSTNode *rchild;
};