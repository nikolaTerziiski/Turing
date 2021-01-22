#include <iostream>
#include "Node.h"
#pragma once
//Tape  a b c b a _ _ _ _ _ 
class Machine {
	private:
		Node* first;
		Node* iterator;
	
		void insertString(std::string& s);
		//Moves the iterator to the right
		void moveLeft();
		//Moves the iterator to the left
		void moreRight();
		//Checks if is palindrome

		//Moves the iterator to the first position so it can start iterate from the start
		void refresh();

		//The algorithm for the palindrome machine
		bool validateMachine();
	public:
		Machine() {
			first = iterator = nullptr;
		}
		Machine(std::string& input) {
			this->insertString(input);
		}
	
		~Machine() {
			if (this->first->data)
			{
				delete[] this->first->prev;
				delete[] this->first->next;
				delete this->first;
				this->first = nullptr;
			}
			else
			{
				delete[] this->first;
			}
		}

		bool isPalindrome() {
			//Calls the refresh function to move the iterator at the start for the algorithm
			this->refresh();

			return validateMachine();
		}
};