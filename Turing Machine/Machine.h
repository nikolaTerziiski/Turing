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

	void insertString(std::string& s)
	{
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
public:
	void print(){
		this->refresh();
		while (this->iterator->next != nullptr)
		{
			std::cout << this->iterator->data << ' ';
			this->moveRight();
		}

		std::cout << std::endl;
	}
};