#include"menu.h"
#include<iostream>
void instructions() {  //show menu
	std::cout << (
		"\n------------------\n"
		"1.insert a node\n"
		"2.delete a node\n"
		"3.preoder traversal\n"
		"4.in order traversal\n"
		"5.post order traversal\n"
		"6.count nodes number\n"
		"7.search an element\n"
		"8.empty or not\n"
		"9.quit\n"
		"-------------------\n"
		"please input your choice: "
	);
}