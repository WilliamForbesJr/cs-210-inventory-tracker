#pragma once

#include <Python.h>
#include <iostream>
#include <cmath>
#include <string>
#include <vector>

#ifndef PYTHON_CONTROLLER_H
#define PYTHON_CONTROLLER_H

/****************************************************************************************
*								PythonController Class									*
*																						*
* Handles calling functions from python file.											*
*																						*
* Methods used to directly call python procs are encapsulated as private methods.		*
*																						*
* The exposed public methods serve as an abstraction layer to hide implementation		*
* details and prevent direct access to Python script file.								*
*																						*
****************************************************************************************/
class PythonController {
	private:
		// Constants to store python proc name strings
		const std::string GET_ITEM_COUNT			= "GetItemCount";
		const std::string PRINT_ITEM_FREQUENCIES = "PrintItemFrequencies";
		const std::string WRITE_TO_FILE			= "WriteToFile";

		/** Call Python function using string param */
		int callIntFunc(std::string proc, std::string param);

		/** Overload - Call Python function using int param */
		int callIntFunc(std::string proc, int param);

		/** Call python func with no params and no return */
		void callProcedure(std::string pName);

	public:
		/* Call python to use searchTerm to fetch a specific item quantity from input file */
		int getItemCount(std::string t_searchTerm);

		/* Call Python to print list of items and their frequencies in input file */
		void printItemFrequencies();

		/* Call python to count item frequencies write them into .dat file */
		void writeToFile();
};

#endif