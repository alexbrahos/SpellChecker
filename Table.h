#ifndef TABLE_H_EXISTS
#define TABLE_H_EXISTS

#include <vector>
#include <iostream>
#include <string>
#include "Node.h"

class Table {

	public:
		std::vector<Node*> categories;
		Table();
		~Table();
		void add(std::string input);
		bool foundElement(std::string input);
		std::string compare(std::string input);
		void firstTwo(std::string input);
		void print();
		void printRow(int num);

};

#endif
