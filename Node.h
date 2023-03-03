#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS

#include <iostream>
#include <string>

class Node {

	public:
		Node* next;
		std::string word;
		Node();
		Node(std::string input);
		void removeNext();

 };

#endif
