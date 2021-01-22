#include <iostream>
#include "fstream"
#include "PalindromeMachine.h"
#include "CryptoMachine.h"
#include "BinaryTransformMachine.h"

//Create struct double linkedlist for the tape of the turing machine

//Turing machine about palindrome which have the methods:
//insert the string from the given path, move to the left, move to the right, validate, refresh
//We take the input string from the txt file names "input.txt"
//Then we have scan method(validate)
//Validate returns true or false if the text from the file is palindrome

int main()
{
    //Read method, which takes the input from txt file
	//std::string output;
	//std::ifstream in;
	//in.open("input.txt", std::ios::in);
	//if (!in.is_open())
	//{
	//	return 1;
	//}

	//while (!in.eof())
	//{
	//	in >> output;
	//	std::cout << output;
	//}


	//Declaration of the strings one palindrom and one non-palindrome
	std::string palindrome = "abccba";
	std::string nonPalindrome = "rannndom";
	std::string result;

	PalindromeMachine machine(nonPalindrome);
	PalindromeMachine machine2(palindrome);

	CryptoMachine crypto(nonPalindrome, machine.isPalindrome());
	CryptoMachine crypto2(palindrome, machine2.isPalindrome());

	BinaryTransformMachine transform(palindrome); //All should be 1
	BinaryTransformMachine transform2(nonPalindrome); //There should be only 2 ones

	std::cout << std::endl;
}
