#include <iostream>
class BSTNode
{
public:
	int key;  //关键字
	BSTNode *left;  //左子节点
	BSTNode *right; //右子节点
	BSTNode *parent;  //父节点

	BSTNode(int k = 0, BSTNode *l = NULL, BSTNode *r = NULL, BSTNode *p = NULL) : key(k), left(l), right(r), parent(p) {};  //初始化列表
};
