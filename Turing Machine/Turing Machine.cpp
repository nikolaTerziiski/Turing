#include <iostream>
#include "fstream"
#include "PalindromeMachine.h"
#include "CryptoMachine.h"

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


	std::string palindrome = "acbabca";
	std::string nonPalindrome = "rannndom";
	std::string result;

	Machine machine(nonPalindrome);
	Machine machine2(palindrome);

	CryptoMachine crypto(nonPalindrome, machine.isPalindrome());
	CryptoMachine crypto2(palindrome, machine2.isPalindrome());

	crypto.Print();
	std::cout << std::endl;
	crypto2.Print();

}
