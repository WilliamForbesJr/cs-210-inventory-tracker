#include "InputController.h"

std::string InputController::getSearchTerm() {
	return m_searchTerm;
}



int InputController::getMenuChoice() {
	return m_menuChoice;
}



void InputController::fetchUserSearchTerm() {
	std::cin >> this->m_searchTerm;
}



void InputController::fetchUserMenuInput() {
	char initialInput = _getch();
	int userInput;

	// Validate input for invalid characters or out-of-bounds range
	try
	{
		userInput = initialInput - 48; // convert inputted char ASCII to integer

		if (userInput > 4 || userInput < 1) {
			throw std::invalid_argument("Invalid Entry. Please enter a number 1 - 4");
		}
	}

	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
		fetchUserMenuInput();
	}

	this->m_menuChoice = userInput;
}



std::map<std::string, int> InputController::readFile(std::string t_file) {
	std::ifstream inFS;

	// key/value placeholder variables
	int value;
	std::string key;

	// ItemMap used to render histogram
	std::map<std::string, int> itemMap;

	inFS.open(t_file);

	if (!inFS.is_open()) {
		std::cout << "ERROR READING FILE";
	}

	// Iterate through file data and populate temperature and cities vectors
	while (!inFS.eof()) {
		inFS >> key;
		inFS >> value;
			
		itemMap.insert(std::pair<std::string, int>(key, value));
	}

	inFS.close();

	return itemMap;
}

