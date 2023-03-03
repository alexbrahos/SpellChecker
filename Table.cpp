#include <iostream>
#include <vector>
#include "Node.h"
#include <string>
#include "Table.h"

Table::Table() {
	for (int i = 0; i < 26; i++) {
		categories.push_back(NULL);
	} //end for
} //end constructor


Table::~Table() {

	//create the table with enough rows
	for (int i = 0; i < 10; i++) {

		if (categories[i] != NULL) {
			categories[i]->removeNext();
		}
		delete categories[i];

	} //end for

} //end destructor


void Table::add(std::string input) {

	int category;

	//category = #of first letter (i.e. america category is 0, hello category is 8, etc.)
	std::string allLetters = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		if (input.at(0) == allLetters.at(i)) {
			category = i;
		} //end if
	} //end for

	if (categories[category] == NULL) {

		categories[category] = new Node(input);

	} //end if null, start else
	else {

		Node* temp = categories[category];
		while (temp->next != NULL) {

			temp = temp->next;

		} //end while

		temp->next = new Node(input);

	} //end else

} //end add


bool Table::foundElement(std::string input) {

	//check all the words in the correct row to see if the word exists
	int category;

	//category = #of first letter (i.e. america category is 0, hello category is 8, etc.)
	std::string allLetters = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		if (input.at(0) == allLetters.at(i)) {
			category = i;
		} //end if
	} //end for

	if (categories[category] != NULL) {

		Node* temp = categories[category];
		while (temp != NULL) {
			if (temp->word == input) {
				return true;
			}
			temp = temp->next;
		} //end while

	} //end if

	return false;

} //end foundElement


std::string Table::compare(std::string input) {

	std::string comp1;
	std::string comp2;
	std::string didYouMean;
	float match = 0.0;
	int correct;

	int category;

	//category = #of first letter (i.e. america category is 0, hello category is 8, etc.)
	std::string allLetters = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		if (input.at(0) == allLetters.at(i)) {
			category = i;
		} //end if
	} //end for


	Node* temp = categories[category];
	while (temp != NULL) { //compare to every word in row

		comp1 = input;
		comp2 = temp->word;
		correct = 0;

		if ((input.size() < comp2.size() - 2) || (input.size() > comp2.size() + 2)) {
			goto notPossible;
		}

		for (int i = 0; i < input.size(); i++){

			for (int j = 0; j < comp2.size(); j++) {

				if (comp1.at(0) == comp2.at(j)) {
					correct++;
					comp2.erase(j,1);
					break;
				} //end if

			} //end inside for

			comp1.erase(0,1); //whether a match was found or not, move onto the next letter

		} //end outside for

		if (match < ((float)correct) / ((float)temp->word.size())) { //get highest & match
			match = ((float)correct) / ((float)temp->word.size());
			didYouMean = temp->word;
		}

		notPossible:
		temp = temp->next;
	} //end while

	if (match < 0.6) {
		return "WORDNOTFOUND";
	}

	return didYouMean;

} //end compare


void Table::firstTwo(std::string input) {

	int category;

	//category = #of first letter (i.e. america category is 0, hello category is 8, etc.)
	std::string allLetters = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i++) {
		if (input.at(0) == allLetters.at(i)) {
			category = i;
		} //end if
	} //end for

	Node* temp = categories[category];
	while (temp != NULL) {

		if (temp->word.at(1) == input.at(1)) {
			std::cout << temp->word << std::endl;
		} //end if
		temp = temp->next;

	} //end while

} //end firstTwo


void Table::print() {

	Node* temp = NULL;
	for (int i = 0; i < 26; i++) {

		std::cout << i << ": ";
		temp = categories[i];
		while (temp != NULL) {

			std::cout << temp->word << " ";
			temp = temp->next;

		} //end while

		std::cout << std::endl;

	} //end for

} //end print


void Table::printRow(int num) {

	Node* temp = categories[num];
	std::cout << "Row " << num << ": ";

	while (temp != NULL) {

		std::cout << temp->word << " ";
		temp = temp->next;

	} //end while

	std::cout << std::endl;

} //end printRow