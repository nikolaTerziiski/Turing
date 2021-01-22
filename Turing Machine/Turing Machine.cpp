#include <iostream>
#include "fstream"
#include "PalindromeMachine.h"
#include "CryptoMachine.h"
#include "BinaryTransformMachine.h"

//Create struct double linkedlist for the tape of the turing machine
//Every machine inherits the Machine class, which has inside the Tape(node), moveLeft, moveRight, insertString(for the Node) and Print

//The basic machine is about palindrome which have the methods:
//We take the input string from the txt file named "input.txt"
//Then we have scan method(validate)
//Validate returns true or false if the text from the file is palindrome

int main()
{
    //Read method, which takes the input from txt file
	//First method where the palindrome is correct
	std::string palndr;
	std::ifstream in;
	in.open("input.txt", std::ios::in);
	if (!in.is_open())
	{
		return 1;
	}
	while (!in.eof())
	{
		in >> palndr;
	}
	PalindromeMachine palindromeMachine(palndr);
	bool isPalndr = palindromeMachine.isPalindrome();
	CryptoMachine cryptoMachine(palndr, isPalndr);
	cryptoMachine.Print();

	BinaryTransformMachine transform(palndr);
	transform.Print();

	//Local Testing
	//Declaration of the strings one palindrom and one non-palindrome
	/*std::string palindrome = "abccba";
	std::string nonPalindrome = "rannndom";
	std::string result;*/

	//Creating the palindrome machine with every string
	//PalindromeMachine machine(nonPalindrome);
	//PalindromeMachine machine2(palindrome);

	//Encrypting every string, depends on if the string is palindrome or not
	//CryptoMachine crypto(nonPalindrome, machine.isPalindrome());
	//CryptoMachine crypto2(palindrome, machine2.isPalindrome());

	//Changing the machine with while loop inside it
	//BinaryTransformMachine transform(palindrome); //All should be 1
	//BinaryTransformMachine transform2(nonPalindrome); //There should be only 2 ones

	/*crypto.Print();
	crypto2.Print();

	transform.Print();
	transform2.Print();
	std::cout << std::endl;*/

	//Multitape turing machine
	//If we have lets say 3 nodes we just convert each node into new node where the first is written then the next symbol of the fist is for example: '#'
	//So it can separate the machines. After we wrtie the '#' the next node of separator is the second node or the second tape. Then we 
	// write again '#' symbol. And at last the next node of the second separator is the last or third node or tape.


}
