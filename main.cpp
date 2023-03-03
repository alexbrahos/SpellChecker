#include <iostream>
#include <fstream>
#include <string>
#include "Node.h"
#include "Table.h"
#include "TimeInterval.h"

int main() {

	Table t;
	std::ifstream inFile;
	std::string currentWord;
	inFile.open("Dictionary.txt");

	//Populate hashtable
	while (getline(inFile, currentWord)) {
		
		currentWord.erase(currentWord.size()-1, 1);
		for (int i = 0; i < currentWord.size(); i++) {
			currentWord.at(i) = tolower(currentWord.at(i));
		} //end for
		t.add(currentWord);

	} //end while
	inFile.close();
	

	std::string userInput;
	std::cout << "Enter a word: ";
	std::cin >> userInput;
	std::cin.ignore();

	std::string yesNoInput;
	TimeInterval timer;

	timer.start();
	Label:
	if (t.foundElement(userInput)) { //case 1, use timer
		std::cout << std::endl << "True" << std::endl;
		//timer.start(); //TIMER START
		t.firstTwo(userInput);
		timer.stop(); //TIMER STOP
		std::cout << timer.GetInterval() << std::endl;
	} //end if foundElement, start else if compare
	else if (t.compare(userInput) != "WORDNOTFOUND") { //case 2, go back to case 1
		//timer.start(); //TIMER START
		userInput = t.compare(userInput);
		timer.stop(); //TIMER STOP
		std::cout << timer.GetInterval() << "Did you mean " << userInput << "? (Y/N): ";
		std::cin >> yesNoInput;
		std::cin.ignore();
		if (yesNoInput == "Y") { //user did want that word
			goto Label;
		} //end inside if Y, start else if N 
		else if (yesNoInput == "N") {
			std::cout << std::endl << "False" << std::endl;
		} //end inside else if N, start else
		else {
			std::cout << std::endl << "Input not understood - Ending Program.";
		}
	} //end else if compare, start else
	else { //case 3
		std::cout << std::endl << "False";
	}
}
