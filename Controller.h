#pragma once

#include "PythonController.h"
#include "ViewController.h"
#include "InputController.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

/****************************************************************************************
*								Controller Class										*
*																						*
* Handles dispatching actions and orchestrating between all controllers					*
*																						*
****************************************************************************************/
class Controller {
	public:
		/** Action dispatcher: Dispatches appropriate action from python controller based on user's menu selection */
		void dispatchAction(PythonController t_python, ViewController t_view, InputController t_input);

		/* Init function instantiates python controller and loops program until user exits */
		void init();
};

#endif