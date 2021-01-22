#include <iostream>
#include "Node.h"
#include "BinaryValidationMachine.h"
#include "Machine.h"

class BinaryTransformMachine : Machine {
private:
	BinaryValidationMachine machine;

	void insertString(std::string& s);
	//Moves the iterator to the right
	
	//The algorithm for the transforming machine
	void operate();

	//Check if the numbers are equal
	bool areEqual();

	//Transform the two chars to 1 if they are equal and to 0 if they are not
	void transformToNumbers(bool equal);

	//Giving the node as string, to check does it contains letters
	std::string nodeAsWord();
public:
	BinaryTransformMachine() {
		first = iterator = nullptr;
	}

	BinaryTransformMachine(std::string& input) {
		this->insertString(input);

		this->operate();
	}

	~BinaryTransformMachine() {
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

};
