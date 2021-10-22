#pragma once

#include <iostream>
#include <Windows.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <map>  
#include <utility>  

#ifndef INPUT_CONTROLLER_H
#define INPUT_CONTROLLER_H

/****************************************************************************************
*								InputController Class									*
*																						*
*			Handles user interaction such as storing and fetching user input			*
*																						*
****************************************************************************************/
class InputController {
	private:
		// Value user selects for search operations
		std::string m_searchTerm;

		// User's menu option selection
		int m_menuChoice;

	public:
		/* Enumeration values for menu options. Using enum values here as it's a bit cleaner and can be extensible for future additions */
		enum MenuOption {
			PRINT_ITEM_FREQUENCIES = 1,
			GET_ITEM_COUNT = 2,
			GENERATE_HISTOGRAM = 3,
			EXIT_PROGRAM = 4
		};
	
		/* UserValue Getter */
		std::string getSearchTerm();

		/* MenuChoice Getter */
		int getMenuChoice();

		/** Parses user input for when user selects a number value for multiplication operations */
		void fetchUserSearchTerm();

		/** Parses user input for user's menu choice. Same parsing as fetchUserValueInput except we also check for valid integer range 1-3 */
		void fetchUserMenuInput();

		/* Read .dat file and return map of items and their corresponding values */
		std::map<std::string, int> readFile(std::string t_file);
};

#endif