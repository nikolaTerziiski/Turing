#include <iostream>
#include "Node.h"
#include "Machine.h"

#pragma once
//Tape  a b c b a _ _ _ _ _ 
class PalindromeMachine : Machine {
	private:
		//The algorithm for the palindrome machine
		bool validateMachine();
	public:
		PalindromeMachine() {
			first = iterator = nullptr;
		}
		PalindromeMachine(std::string& input) {
			this->insertString(input);
		}
	
		~PalindromeMachine() {
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
		void Print() {
			this->print();
		}
};