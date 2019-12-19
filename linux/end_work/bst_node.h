#include <iostream>
class BSTNode
{
public:
	void *key;  //关键字
	BSTNode *lchild;  //左子节点
	BSTNode *rchild; //右子节点
	BSTNode *parent;  //父节点

	BSTNode(void *k = NULL, BSTNode *l = NULL, BSTNode *r = NULL, BSTNode *p = NULL) : key(k), lchild(l), rchild(r), parent(p) {};  //初始化列表
};
