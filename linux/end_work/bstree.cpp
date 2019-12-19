#include "bstree.h"

BSTree::BSTree() :root(NULL) {};  //构造函数

BSTree::~BSTree()  //析构函数
{
	destroy();
}

void BSTree::insert(void *key)  //将key节点插入到二叉树中
{
	BSTNode *z = new BSTNode(key, NULL, NULL, NULL);  //根据插入的key生成新的二叉树节点(z)
	if (z == NULL)
	{
		return;  //如果z里面的值为空，则停止函数的执行
	}
	insert(root, z);  //把新生的节点(z)传入树根
}


void BSTree::PreOrder(BSTNode *tree)  //前序二叉树遍历
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		PreOrder(tree->lchild);
		PreOrder(tree->rchild);
	}
}
void BSTree::PreOrder()
{
	PreOrder(root);  //传入根节点
}

void BSTree::InOrder(BSTNode *tree)  //中序二叉树遍历
{
	if (tree != NULL)
	{
		InOrder(tree->lchild);
		cout << tree->key << " ";
		InOrder(tree->rchild);
	}
}
void BSTree::InOrder()
{
	InOrder(root);  //传入根节点
}


void BSTree::PostOrder(BSTNode *tree)  //后序二叉树遍历
{
	if (tree != NULL)
	{
		PostOrder(tree->lchild);
		PostOrder(tree->rchild);
		cout << tree->key << " ";
	}
}
void BSTree::PostOrder()
{
	PostOrder(root);  //传入根节点
}


BSTNode *BSTree::search(BSTNode *x, void *key)  //递归实现，在”二叉树x“中查找key节点
{
	if (x == NULL || key == x->key)
	{
		return x;
	}
	if (key < x->key)
	{
		return search(x->lchild, key);
	}
	else
	{
		return search(x->rchild, key);
	}
}
BSTNode *BSTree::search(void *key)
{
	return search(root, key);  //传入根节点和待查找的关键字key
}


BSTNode *BSTree::IteratorSearch(BSTNode *x, void *key)  //迭代实现，在“二叉树x”中查找key节点
{
	while (x != NULL && key != x->key)
	{
		if (key < x->key)
		{
			x = x->lchild;
		}
		else
		{
			x = x->rchild;
		}
	}
	return x;
}
BSTNode *BSTree::IteratorSearch(void *key)
{
	return IteratorSearch(root, key);  //传入根节点和待查找的关键字key
}


BSTNode *BSTree::minimum(BSTNode *tree)  //查找最小节点：返回tree为根节点的二叉树的最小节点。
{
	if (tree == NULL)
	{
		return NULL;
	}
	while (tree->lchild != NULL)
	{
		tree = tree->lchild;
	}
	return tree;
}


BSTNode *BSTree::maximum(BSTNode *tree)  //查找最大节点：返回tree为根节点的二叉树的最大节点。
{
	while (tree->rchild != NULL)
	{
		tree = tree->rchild;
	}
	return tree;
}


BSTNode *BSTree::successor(BSTNode *x)  //找节点(x)的后继节点，也就是该节点的右子树中的最小节点
{
	BSTNode *y = NULL;
	if (x->rchild != NULL)
	{
		return minimum(x->rchild);
	}

	// 如果x没有右子节点。则x有以下两种可能：
	// （1） x是"一个左子节点"，则"x的后继节点"为 "它的父节点"。
	// （2） x是"一个右子节点"，则查找"x的最低的父节点，并且该父节点要具有左子节点"，找到的这个"最低的父节点"就是"x的后继节点"。

	y = x->parent;
	while (y != NULL && x == y->rchild)
	{
		x = y;
		y = y->parent;
	}
	return y;
}


BSTNode *BSTree::predecessor(BSTNode *x)  //找节点(x)的前驱节点是该节点的左子树中的最大节点。
{
	BSTNode *y = NULL;
	if (x->lchild != NULL)
	{
		return maximum(x->lchild);
	}

	// 如果x没有左子节点。则x有以下两种可能：
	//（1）x是"一个右子节点"，则"x的前驱节点"为 "它的父节点"。
	//（2）x是"一个左子节点"，则查找"x的最低的父节点，并且该父节点要具有右子节点"，找到的这个"最低的父节点"就是"x的前驱节点"。

	y = x->parent;
	while (y != NULL && x == y->lchild)
	{
		x = y;
		y = y->parent;
	}
	return y;
}


void BSTree::insert(BSTNode *&tree, BSTNode *z)  // 将节点(z)插入到二叉树(tree)中
{
	BSTNode *y = NULL;
	BSTNode *x = tree;

	while (x != NULL)  // 查找z的插入位置
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->lchild;
		}
		else
		{
			x = x->rchild;
		}
	}

	z->parent = y;
	if (y == NULL)
	{
		tree = z;
	}
	else
		if (z->key < y->key)
		{
			y->lchild = z;
		}
		else
		{
			y->rchild = z;
		}
}


BSTNode *BSTree::remove(BSTNode *tree, BSTNode *z)  // 删除二叉树(tree)中的节点(z)，并返回被删除的节点
{
	BSTNode *x = NULL;
	BSTNode *y = NULL;

	if (z->lchild == NULL || z->rchild == NULL)
	{
		y = z;
	}
	else
	{
		y = successor(z);
	}

	if (y->lchild != NULL)
	{
		x = y->lchild;
	}
	else
	{
		x = y->rchild;
	}

	if (x != NULL)
	{
		x->parent = y->parent;
	}

	if (y->parent == NULL)
	{
		tree = x;
	}
	else
		if (y == y->parent->lchild)
		{
			y->parent->lchild = x;
		}
		else
		{
			y->parent->rchild = x;
		}

	if (y != z)
	{
		z->key = y->key;
	}
	return y;
}


void BSTree::remove(void *key)  // 删除二叉树(tree)中的节点(z)，并返回被删除的节点
{
	BSTNode *z, *node;
	z = IteratorSearch(root, key);  //根据给定的key，查找树中是否存在key节点
	if (z != NULL)
	{
		node = remove(root, z);  //传入树根以及待删除的节点(z)
		if (node != NULL)
		{
			delete node;
		}
	}
}


void BSTree::destroy(BSTNode *&tree)  //销毁二叉树
{
	if (tree == NULL)
	{
		return;  //停止函数的执行
	}
	if (tree->lchild != NULL)
	{
		return destroy(tree->lchild);
	}
	if (tree->rchild != NULL)
	{
		return destroy(tree->rchild);
	}
	delete tree;
	tree = NULL;
}


void BSTree::destroy()  //销毁二叉树
{
	destroy(root);
}