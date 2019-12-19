#include <iostream>
#include <stdlib.h>
#include "bstree.h"
using namespace std;

/***********************************************************/
/*  ��������� ���� ���롢���������ҡ�ɾ��������
/**********************************************************/

int main(void)
{
	/************************/
	/*          ����
	/************************/
	BSTree *tree = new BSTree();
	int array[6] = { 11, 33, 18, 24, 44, 66 };
	cout << "��������ֵ��" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << array[i] << " ";
		tree->insert(&array[i]);  //���ò��뺯�������ɶ��������
	}

	cout << endl << endl;


	/************************/
	/*          ����
	/************************/
	cout << "ǰ�������";
	tree->PreOrder();
	cout << endl;

	cout << "���������";
	tree->InOrder();
	cout << endl;

	cout << "���������";
	tree->PostOrder();
	cout << endl << endl;


	/************************/
	/*          ����
	/************************/
	int keyword;  //���ҽڵ�Ĺؼ���
	cout << "������Ҫ���ҵĽڵ㣺";
	cin >> keyword;
	cout << endl;
	BSTNode *node = tree->IteratorSearch(keyword);  //��ȡ��ֵ�ĵ�ַ
	if (node)  //�ж���û�е�ַ
	{
		cout << "�ؼ���Ϊ��" << keyword << "���Ľڵ㣬���ڡ�" << endl;
	}
	else
	{
		cout << "�ؼ���Ϊ��" << keyword << "���Ľڵ㣬�����ڡ�" << endl;
	}
	cout << endl << endl;


	/************************/
	/*          ɾ��
	/************************/
	int DelNode;  //Ҫɾ���Ľڵ�
	cout << "������Ҫɾ���Ľڵ㣺";
	cin >> DelNode;
	tree->remove(DelNode);
	cout << endl;

	cout << "ɾ��������(ǰ��)������";
	tree->PreOrder();
	cout << endl;
	cout << "ɾ��������(����)������";
	tree->InOrder();
	cout << endl;
	cout << "ɾ��������(����)������";
	tree->PostOrder();
	cout << endl << endl;


	/************************/
	/*          ����
	/************************/
	tree->destroy();


	system("pause");
	return 0;
}