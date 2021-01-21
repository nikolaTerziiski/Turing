#include "PalindromeMachine.h"

// a b a b a
void Machine::insertString(std::string& s) {

	Node* q;
	iterator = new Node;

	//Declaration of iterator
	iterator->prev = iterator->next = nullptr;
	first = iterator;
	for (int i = 0; i < s[i] != '\0'; i++)
	{
		q = new Node;
		q->prev = iterator;
		q->next = nullptr;
		q->data = s[i];
		iterator->next = q;
		iterator = q;
	}

	iterator->next = new Node();
	iterator->next->prev = iterator;
	iterator->next->data = NULL;

	iterator = first;
}

void Machine::moveLeft() {
	iterator = iterator->prev;
}
void Machine::moreRight() {
	iterator = iterator->next;
}

bool Machine::validateMachine() {
	char currentElement = this->iterator->data;
	this->iterator->data = NULL;
	if (this->iterator->next->data == NULL)
	{
		return true;
	}

	while (this->iterator->next->data != NULL)
	{
		this->moreRight();
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

void Machine::refresh() {
	this->iterator = first->next;
}