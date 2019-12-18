#include <iostream>
using namespace std;

class BSTNode
{
public:
	int key;  //�ؼ���
	BSTNode *left;  //���ӽڵ�
	BSTNode *right; //���ӽڵ�
	BSTNode *parent;  //���ڵ�

	BSTNode(int k = 0, BSTNode *l = NULL, BSTNode *r = NULL, BSTNode *p = NULL) : key(k), left(l), right(r), parent(p) {};  //��ʼ���б�
};


class BSTree
{
public:
	BSTree();  //���캯��
	~BSTree();  //��������

	void insert(int key);  //��key�ڵ���뵽��������

	void PreOrder();  //ǰ�����������
	void InOrder();  //�������������
	void PostOrder();  //�������������

	BSTNode *search(int key);  //�ݹ�ʵ�֣��ڶ������в���key�ڵ�
	BSTNode *IteratorSearch(int key);  //����ʵ�֣��ڶ������в���key�ڵ�

	BSTNode *successor(BSTNode *x);  //�ҽڵ�(x)�ĺ�̽ڵ㡣��������"������������ֵ���ڸýڵ�"��"��С�ڵ�"
	BSTNode *predecessor(BSTNode *x);  //�ҽڵ�(x)��ǰ���ڵ㡣��������"������������ֵС�ڸýڵ�"��"���ڵ�"

	void remove(int key);  //ɾ��key�ڵ�

	void destroy();  //���ٶ�����


private:
	BSTNode *root;  //���ڵ�
	void PreOrder(BSTNode *tree);  //ǰ�����������
	void InOrder(BSTNode *tree);  //�������������
	void PostOrder(BSTNode *tree);  //�������������

	BSTNode *search(BSTNode *x, int key);  //�ݹ�ʵ�֣��ڡ�������x���в���key�ڵ�
	BSTNode *IteratorSearch(BSTNode *x, int key);  //����ʵ�֣��ڡ�������x���в���key�ڵ�

	BSTNode *minimum(BSTNode *tree);  //������С�ڵ㣺����treeΪ���ڵ�Ķ���������С�ڵ�
	BSTNode *maximum(BSTNode *tree);  //�������ڵ㣺����treeΪ���ڵ�Ķ����������ڵ�

	void insert(BSTNode *&tree, BSTNode *z);  // ���ڵ�(z)���뵽������(tree)��

	BSTNode *remove(BSTNode *tree, BSTNode *z);  // ɾ��������(tree)�еĽڵ�(z)�������ر�ɾ���Ľڵ�

	void destroy(BSTNode *&tree);  //���ٶ�����
};