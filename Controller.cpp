#include "Controller.h"

void Controller::dispatchAction(PythonController t_python, ViewController t_view, InputController t_input) {
	// Exit function is user selects exit choice
	if (t_input.getMenuChoice() == t_input.EXIT_PROGRAM) {
		system("CLS");
		return;
	}

	// If user doesn't select EXIT_PROGRAM, refresh the screen and prompt for value
	system("CLS");

	// After refresh, run appropriate python action from menuChoice value
	switch (t_input.getMenuChoice()) {
		// Print each item and frequency
		case t_input.PRINT_ITEM_FREQUENCIES:
			t_python.printItemFrequencies();
			break;
		// Prompt user for input, get search term, pass it into python to get result & use view to print
		case t_input.GET_ITEM_COUNT:
			t_view.promptUser();
			t_input.fetchUserSearchTerm();
			t_view.printItemCount(t_input.getSearchTerm(), t_python.getItemCount((t_input.getSearchTerm())));
			break;
		// Use python to write data from input to file, Pass newly-created file into input to read, and output data using view controller.
		case t_input.GENERATE_HISTOGRAM:
			t_python.writeToFile();
			t_view.renderHistogram(t_input.readFile("frequency.dat"));
			break;
		default:
			break;
		}

	t_view.pressKeyToContinue();
}



void Controller::init() {
	// Instantiate Classes
	PythonController pythonController;
	InputController input;
	ViewController view;

	// Execute program loop until user selects quit
	while (input.getMenuChoice() != input.EXIT_PROGRAM) {
		view.printMenu();
		input.fetchUserMenuInput();
		dispatchAction(pythonController, view, input);
	}
}