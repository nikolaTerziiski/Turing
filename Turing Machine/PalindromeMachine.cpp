#include "PalindromeMachine.h"

// a b a b a

bool PalindromeMachine::validateMachine() {
	char currentElement = this->iterator->data;
	this->iterator->data = NULL;
	if (this->iterator->next->data == NULL)
	{
		return true;
	}

	while (this->iterator->next->data != NULL)
	{
		this->moveRight();
	}

	if (this->iterator->data == currentElement)
	{

		this->iterator->data = NULL;

		while (this->iterator->prev->data != NULL)
		{
			this->moveLeft();
		}
		validateMachine();
	}
	else
	{
		return false;
	}
}