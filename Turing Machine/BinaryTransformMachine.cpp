#include "BinaryTransformMachine.h"

void BinaryTransformMachine::operate()
{
	std::string word = this->nodeAsWord();
	while (this->machine.CheckIfContainsLetters(word))
	{
		bool equal = this->areEqual();
		this->transformToNumbers(equal);

		word = this->nodeAsWord();
	}
}

bool BinaryTransformMachine::areEqual()
{
	this->refresh();
	
	//Taking the first letter after all 0 and 1, cuz if it takes the first it can return number and it wont be correct
	while (this->iterator->data == '0' || this->iterator->data == '1')
	{
		this->moveRight();
	}

	char firstLetter = this->iterator->data;

	//Taking the last letter after until it finds number or nullptr(for the last element)
	while (this->iterator->next != nullptr && this->iterator->data != '0' && this->iterator->data != '1')
	{
		this->moveRight();
	}
	this->moveLeft();
	char secondLetter = this->iterator->data;

	return secondLetter == firstLetter ? true : false;
}

void BinaryTransformMachine::transformToNumbers(bool equal)
{
	this->refresh();

	while (this->iterator->data == '0' || this->iterator->data == '1')
	{
		this->moveRight();
	}

	equal == true ? this->iterator->data = '1' : this->iterator->data = '0';

	while (this->iterator->next != nullptr)
	{
		this->moveRight();
	}
	this->moveLeft();

	while (this->iterator->data == '1' || this->iterator->data == '0')
	{
		this->moveLeft();
	}

	equal == true ? this->iterator->data = '1' : this->iterator->data = '0';


}

std::string BinaryTransformMachine::nodeAsWord()
{
	this->refresh();
	std::string result;
	while (this->iterator->next != nullptr)
	{
		result += this->iterator->data;
		this->moveRight();
	}
	return result;
}
