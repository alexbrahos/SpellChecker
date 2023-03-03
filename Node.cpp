#include <iostream>
#include <string>
#include "Node.h"

Node::Node() {

	this->word = "";
	this->next = NULL;

} //end null parameter constructor


Node::Node(std::string input) {

	this->word = input;
	this->next = NULL;

} //end constructor


void Node::removeNext() {
	//recursively delete all nodes in list
	if (this->next != NULL) {
		this->next->removeNext();
	}
	delete this->next;
}