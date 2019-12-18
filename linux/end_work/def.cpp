#include "def.h"

BSTree::BSTree() :root(NULL) {};  //���캯��

BSTree::~BSTree()  //��������
{
	destroy();
}


void BSTree::insert(int key)  //��key�ڵ���뵽��������
{
	BSTNode *z = new BSTNode(key, NULL, NULL, NULL);  //���ݲ����key�����µĶ������ڵ�(z)
	if (z == NULL)
	{
		return;  //���z�����ֵΪ�գ���ֹͣ������ִ��
	}
	insert(root, z);  //�������Ľڵ�(z)��������
}


void BSTree::PreOrder(BSTNode *tree)  //ǰ�����������
{
	if (tree != NULL)
	{
		cout << tree->key << " ";
		PreOrder(tree->left);
		PreOrder(tree->right);
	}
}
void BSTree::PreOrder()
{
	PreOrder(root);  //������ڵ�
}


void BSTree::InOrder(BSTNode *tree)  //�������������
{
	if (tree != NULL)
	{
		InOrder(tree->left);
		cout << tree->key << " ";
		InOrder(tree->right);
	}
}
void BSTree::InOrder()
{
	InOrder(root);  //������ڵ�
}


void BSTree::PostOrder(BSTNode *tree)  //�������������
{
	if (tree != NULL)
	{
		PostOrder(tree->left);
		PostOrder(tree->right);
		cout << tree->key << " ";
	}
}
void BSTree::PostOrder()
{
	PostOrder(root);  //������ڵ�
}


BSTNode *BSTree::search(BSTNode *x, int key)  //�ݹ�ʵ�֣��ڡ�������x���в���key�ڵ�
{
	if (x == NULL || key == x->key)
	{
		return x;
	}
	if (key < x->key)
	{
		return search(x->left, key);
	}
	else
	{
		return search(x->right, key);
	}
}
BSTNode *BSTree::search(int key)
{
	return search(root, key);  //������ڵ�ʹ����ҵĹؼ���key
}


BSTNode *BSTree::IteratorSearch(BSTNode *x, int key)  //����ʵ�֣��ڡ�������x���в���key�ڵ�
{
	while (x != NULL && key != x->key)
	{
		if (key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}
BSTNode *BSTree::IteratorSearch(int key)
{
	return IteratorSearch(root, key);  //������ڵ�ʹ����ҵĹؼ���key
}


BSTNode *BSTree::minimum(BSTNode *tree)  //������С�ڵ㣺����treeΪ���ڵ�Ķ���������С�ڵ㡣
{
	if (tree == NULL)
	{
		return NULL;
	}
	while (tree->left != NULL)
	{
		tree = tree->left;
	}
	return tree;
}


BSTNode *BSTree::maximum(BSTNode *tree)  //�������ڵ㣺����treeΪ���ڵ�Ķ����������ڵ㡣
{
	while (tree->right != NULL)
	{
		tree = tree->right;
	}
	return tree;
}


BSTNode *BSTree::successor(BSTNode *x)  //�ҽڵ�(x)�ĺ�̽ڵ㣬Ҳ���Ǹýڵ���������е���С�ڵ�
{
	BSTNode *y = NULL;
	if (x->right != NULL)
	{
		return minimum(x->right);
	}

	// ���xû�����ӽڵ㡣��x���������ֿ��ܣ�
	// ��1�� x��"һ�����ӽڵ�"����"x�ĺ�̽ڵ�"Ϊ "���ĸ��ڵ�"��
	// ��2�� x��"һ�����ӽڵ�"�������"x����͵ĸ��ڵ㣬���Ҹø��ڵ�Ҫ�������ӽڵ�"���ҵ������"��͵ĸ��ڵ�"����"x�ĺ�̽ڵ�"��

	y = x->parent;
	while (y != NULL && x == y->right)
	{
		x = y;
		y = y->parent;
	}
	return y;
}


BSTNode *BSTree::predecessor(BSTNode *x)  //�ҽڵ�(x)��ǰ���ڵ��Ǹýڵ���������е����ڵ㡣
{
	BSTNode *y = NULL;
	if (x->left != NULL)
	{
		return maximum(x->left);
	}

	// ���xû�����ӽڵ㡣��x���������ֿ��ܣ�
	//��1��x��"һ�����ӽڵ�"����"x��ǰ���ڵ�"Ϊ "���ĸ��ڵ�"��
	//��2��x��"һ�����ӽڵ�"�������"x����͵ĸ��ڵ㣬���Ҹø��ڵ�Ҫ�������ӽڵ�"���ҵ������"��͵ĸ��ڵ�"����"x��ǰ���ڵ�"��

	y = x->parent;
	while (y != NULL && x == y->left)
	{
		x = y;
		y = y->parent;
	}
	return y;
}


void BSTree::insert(BSTNode *&tree, BSTNode *z)  // ���ڵ�(z)���뵽������(tree)��
{
	BSTNode *y = NULL;
	BSTNode *x = tree;

	while (x != NULL)  // ����z�Ĳ���λ��
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
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
			y->left = z;
		}
		else
		{
			y->right = z;
		}
}


BSTNode *BSTree::remove(BSTNode *tree, BSTNode *z)  // ɾ��������(tree)�еĽڵ�(z)�������ر�ɾ���Ľڵ�
{
	BSTNode *x = NULL;
	BSTNode *y = NULL;

	if (z->left == NULL || z->right == NULL)
	{
		y = z;
	}
	else
	{
		y = successor(z);
	}

	if (y->left != NULL)
	{
		x = y->left;
	}
	else
	{
		x = y->right;
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
		if (y == y->parent->left)
		{
			y->parent->left = x;
		}
		else
		{
			y->parent->right = x;
		}

	if (y != z)
	{
		z->key = y->key;
	}
	return y;
}


void BSTree::remove(int key)  // ɾ��������(tree)�еĽڵ�(z)�������ر�ɾ���Ľڵ�
{
	BSTNode *z, *node;
	z = IteratorSearch(root, key);  //���ݸ�����key�����������Ƿ����key�ڵ�
	if (z != NULL)
	{
		node = remove(root, z);  //���������Լ���ɾ���Ľڵ�(z)
		if (node != NULL)
		{
			delete node;
		}
	}
}


void BSTree::destroy(BSTNode *&tree)  //���ٶ�����
{
	if (tree == NULL)
	{
		return;  //ֹͣ������ִ��
	}
	if (tree->left != NULL)
	{
		return destroy(tree->left);
	}
	if (tree->right != NULL)
	{
		return destroy(tree->right);
	}
	delete tree;
	tree = NULL;
}


void BSTree::destroy()  //���ٶ�����
{
	destroy(root);
}