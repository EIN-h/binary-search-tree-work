#include <iostream>
#include "bstree.h"
#include "menu.h"
using namespace std;
#define TT int

int main() {
	TT root = 5;
	TT a = 1, b = 2, c = 3, d = 4, e = 6, f = 8;

	BSTree<TT> bTree(root);
	bTree.insert(a);
	bTree.insert(b);
	bTree.insert(c);
	bTree.insert(d);
	bTree.insert(e);
	bTree.insert(f);
	std::cout << "*** We have initialize a aTree which have a root[5] and elements[1,2,3,4,5,8] for you ***";

	int command = 0;
	while (command != 9) {
		instructions();
		std::cin >> command;
		switch (command)
		{
		case 1: {
			TT k;
			std::cout << "please enter the key you want to insert: ";
			std::cin >> k;
			bTree.insert((TT)k);
			std::cout << success;
			break;
		}
		case 2: {
			TT k;
			std::cout << "please enter the key you want to delete: ";
			std::cin >> k;
			bTree.remove(k);
			break;
		}
		case 3: {
			if (bTree.countNodes() == 0)
				std::cout << empty;
			else{
				std::cout << "preoder traversal: ";
				bTree.preOrder();
			}
			break;
		}
		case 4: {
			if (bTree.countNodes() == 0)
				std::cout << empty;
			else {
				std::cout << "in order traversal: ";
				bTree.inOrder();
			}
			break;
		}
		case 5: {
			if (bTree.countNodes() == 0)
				std::cout << empty;
			else {
			std::cout << "post order traversal: ";
			bTree.postOrder();
			}
			break;
		}
		case 6: {
			std::cout << "nodes number: ";
			std::cout << bTree.countNodes();
			break;
		}
		case 7: {
			TT k;
			std::cout << "please enter the key you want to search: ";
			std::cin >> k;
			if (bTree.findNode(k))
				std::cout << "The element is in the bstree, you can choose 3/4/5 to print it.";
			else
				std::cout << not_exist;
			break;
		}
		case 8: {
			std::cout << "empty or not: ";
			if(bTree.countNodes() == 0)
				std::cout << "empty";
			else
				std::cout << "not empty";
			break;
		}
		case 9: {
			bTree.makeEmpty();
			std::cout << "Good Bye!";
			break;
		}
		default:
			break;
		}
	}
	cout << endl;
	return 0;
}