#include<iostream>
#include "bstnode.h"
#include "string.h"

template< typename T>
class BSTree//binary search tree
{
public:
	BSTree() = default;//default constructor
	BSTree(const BSTree &bt);//construct by bstree
	BSTree(const T &key);//construct by key

	~BSTree();

	void insert(const T &key);//insert a node into bst
	void remove(const T &key);//remove a node from bst
	void preOrder() const;//preoder traversal
	void inOrder() const;//in order traversal
	void postOrder() const;//post order traversal
	int countNodes() const;//count the amount of nodes
	bool findNode(const T &key) const;//find a node
	void makeEmpty();

private:
	BSTNode<T> *root;
	BSTNode<T> * clone(const BSTNode<T> *bNode);//clone a bst to another
	void insert(const T &key, BSTNode<T> * &t);//insert a node into bst with its root node
	void remove(const T &key, BSTNode<T> * &t);//remove a node from bst with its root node
	BSTNode<T> * findMin(BSTNode<T> *bNode) const;//find the smallest node
	void preOrder(BSTNode<T> *bNode) const;//preoder traversal
	void inOrder(BSTNode<T> *bNode) const;//in order traversal
	void postOrder(BSTNode<T> *bNode) const;//post order traversal
	int countNodes(BSTNode<T> *bNode) const;//count the amount of nodes with its root node
	bool findNode(const T &key, BSTNode<T> *t)  const;//find a node in bst with its root node
	void makeEmpty(BSTNode<T> * &t);
};

/******************************public*****************************/
template< typename T>//default constructor
BSTree<T>::~BSTree() {
	makeEmpty();
};

template< typename T>//construct by bstree
BSTree<T>::BSTree(const BSTree &bstree) {
	if (nullptr != bstree.root) {
		this->root = clone(bstree.root);
	}
	else {
		root = nullptr;
	}
};

template< typename T>//construct by key
BSTree<T>::BSTree(const T &key) {
	root = new BSTNode<T>(key);
}

template< typename T>//insert a node into bst
void BSTree<T>::insert(const T &key) {
	insert(key, root);
};

template< typename T>//remove a node from bst
void BSTree<T>::remove(const T &key) {
	remove(key, root);
};

template< typename T>//preoder traversal
void BSTree<T>::preOrder() const {
	preOrder(root);
};

template< typename T>//in order traversal
void BSTree<T>::inOrder() const {
	inOrder(root);
};

template< typename T>//post order traversal
void BSTree<T>::postOrder() const {
	postOrder(root);
};

template< typename T>//count the amount of nodesa
int BSTree<T>::countNodes() const {
	return countNodes(root);
};

template< typename T>//find a node
bool BSTree<T>::findNode(const T &key) const {
	return findNode(key, root);
};

template< typename T>
void BSTree<T>::makeEmpty() {
	makeEmpty(root);
};

/******************************private*****************************/
template< typename T>//clone a bst to another
BSTNode<T>* BSTree<T>::clone(const BSTNode<T> *node) {
	if (nullptr == node) {
		return nullptr;//if the node dose not exist, then return nullptr
	}
	else {
		return new BSTNode(node->key, clone(node->lchild), clone(node->rchild));//recruse for its left and right children
	}
}

template< typename T>//insert a node into bst with its root node
void BSTree<T>::insert(const T &key, BSTNode<T> * &t) {
	if (nullptr == t) {//find the place that should insert to
		t = new BSTNode<T>(key);
	}
	else if (key < t->key) {//if the key is smaller than this node, then switch to its left child
		insert(key, t->lchild);
	}
	else if (key > t->key) {//if the key is bigger than this node, then switch to its right child
		insert(key, t->rchild);
	}
	else {//can not inser an element that already exists
		std::cout << warning << "Could not insert an element that already exists in the bTree!";
	}
};

template< typename T>//remove a node from bst with its root node
void BSTree<T>::remove(const T &key, BSTNode<T> * &t) {
	if (nullptr == t) {
		std::cout << not_exist;
		return;
	}
	else {
		if (key < t->key) {//if the key is smaller than this node, then switch to its left child
			remove(key, t->lchild);
		}
		else if (key > t->key) {//if the key is bigger than this node, then switch to its right child
			remove(key, t->rchild);
		}
		else if (nullptr != t->lchild && nullptr != t->rchild) {//if the node you want to delete have two child trees, 
																//you can choose to replace this node with
																//the largest node in its left tree or the smallest node in its right tree
																//in order to fufil the rule of BSTree.
			t->key = findMin(t->rchild)->key;//I choose to replace the node with its smallest node in its right tree here
			remove(t->key, t->rchild);//then you have to delete that node in its formal place
		}
		else {//if the node you want to delete have only one child tree, you can simply put its right/left child up a node
			BSTNode<T> * oldNode = t;
			t = (nullptr != t->lchild) ? t->lchild : t->rchild;//check if it have right/left child
			delete oldNode;//delete the old node
			std::cout << success;
		}
	}
};

template< typename T>//find the smallest node
BSTNode<T> * BSTree<T>::findMin(BSTNode<T> *bNode) const {
	if (nullptr != bNode) {//find the node that in its deepest left
		while (nullptr != bNode->lchild) {
			bNode = bNode->lchild;
		}
	}
	return bNode;
}

template< typename T>//preoder traversal
void BSTree<T>::preOrder(BSTNode<T> *bNode) const {
	if (nullptr != bNode) {//root->left->right
		std::cout << bNode->key << " ";
		preOrder(bNode->lchild);
		preOrder(bNode->rchild);
	}
};

template< typename T>//in order traversal
void BSTree<T>::inOrder(BSTNode<T> *bNode) const {
	if (nullptr != bNode) {//left->root->right
		inOrder(bNode->lchild);
		std::cout << bNode->key << " ";
		inOrder(bNode->rchild);
	}
};

template< typename T>//post order traversal
void BSTree<T>::postOrder(BSTNode<T> *bNode) const {
	if (nullptr != bNode) {//left->right->root
		postOrder(bNode->lchild);
		postOrder(bNode->rchild);
		std::cout << bNode->key << " ";
	}
};

template< typename T>//count the amount of nodes with its root node
int BSTree<T>::countNodes(BSTNode<T> *bNode) const {
	if (nullptr != bNode)//using recursion
		return countNodes(bNode->lchild) + countNodes(bNode->rchild) +1;
	else
		return 0;
};

template< typename T>//find a node in bst with its root node
bool BSTree<T>::findNode(const T &key, BSTNode<T> * t) const {
	if (nullptr == t) {//using recursion//if not find it, return false
		return false;
	}
	else if (key < t->key) {
		return findNode(key, t->lchild);
	}
	else if (key > t->key) {
		return findNode(key, t->rchild);
	}
	else {//if find it, return true
		return true;
	}
};

template< typename T>
void BSTree<T>::makeEmpty(BSTNode<T> * &t) {
	if (nullptr != t) {//delete all nodes
		makeEmpty(t->lchild);
		makeEmpty(t->rchild);
		delete t;
	}
	t = nullptr;
};