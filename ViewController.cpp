#include "ViewController.h"

void ViewController::printMenu() {
	std::cout << OPTION_1 << std::endl;
	std::cout << OPTION_2 << std::endl;
	std::cout << OPTION_3 << std::endl;
	std::cout << OPTION_4 << std::endl;
	std::cout << SELECTION_PROMPT << std::endl;
};



void ViewController::pressKeyToContinue() {
	std::cout << CONTINUE_PROMPT << std::endl;
	_getch();
	system("CLS");
}



void ViewController::renderHistogramRow(std::string t_itemName, int t_itemQuantity) {
	std::string graph;

	// Append "*" character to string to generate graph
	for (unsigned int i = 0; i < t_itemQuantity; i++) {
		graph += "*";
	}

	std::cout << t_itemName << ": " << graph << std::endl;
}

void ViewController::printItemCount(std::string t_item, int t_count) {
	std::cout << t_item << ": " << t_count << std::endl;
}



void ViewController::renderHistogram(std::map<std::string, int> t_itemMap) {
	// Take new mapped object and render histogram
	for (std::map<std::string, int>::iterator iter = t_itemMap.begin(); iter != t_itemMap.end(); ++iter)
	{
		std::string itemName = (*iter).first;
		int itemQuantity = (*iter).second;

		renderHistogramRow(itemName, itemQuantity);
	}
}



void ViewController::promptUser() {
	std::cout << SEARCH_PROMPT << std::endl;
}