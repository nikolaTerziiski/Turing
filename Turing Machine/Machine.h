#pragma once
#include "Node.h"

class Machine{
protected:
	Node* first;
	Node* iterator;

	void moveLeft() {
		iterator = iterator->prev;
	}
	void moveRight() {
		iterator = iterator->next;
	}

	void refresh(){
		this->iterator = first->next;
	}

public:
	void print(){
		this->refresh();
		while (this->iterator->next != nullptr)
		{
			std::cout << this->iterator->data << ' ';
			this->moveRight();
		}
	}
};