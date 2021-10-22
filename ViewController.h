#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <map>  

#ifndef VIEW_CONTROLLER_H
#define VIEW_CONTROLLER_H

/****************************************************************************************
*								ViewController Class									*
*																						*
* Handles all rendering and console output logic										*
*																						*
****************************************************************************************/
class ViewController {
	private:
		/* Constant String values for menu content */
		const std::string OPTION_1			= "1 : Display Item Count";
		const std::string OPTION_2			= "2 : Search Specific Item Count";
		const std::string OPTION_3			= "3 : Generate Histogram";
		const std::string OPTION_4			= "4 : Exit";

		const std::string ERROR_MESSAGE		= "There was a problem reading the file.";

		const std::string SEARCH_PROMPT		= "Enter an item to search for";
		const std::string SELECTION_PROMPT	= "Enter your selection as a number 1, 2, 3, or 4.";
		const std::string CONTINUE_PROMPT	= "Press any Key to continue...";

	public:
		/* Render Menu for user in console.*/
		void printMenu();

		/* Prompt User to enter any key using getch(). Throw away input */
		void pressKeyToContinue();

		/** Accepts item name and quantity. Renders number of "*" equal to value to display a histogram row. */
		void renderHistogramRow(std::string t_itemName, int t_itemQuantity);

		/* Print Item name and count to the console*/
		void printItemCount(std::string t_item, int t_count);

		/* Recieves map containing key/value pairs for item and renders entire histogram. key: itemName, value: item quantity */
		void renderHistogram(std::map<std::string, int> t_itemMap);

		/* Output search prompt to user */
		void promptUser();
};

#endif