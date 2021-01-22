#include "CryptoMachine.h"

const char alph[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
std::string CryptoMachine::PalindromeEncrypt(std::string& input) {

	//Basic transformation of the string. Just adding 13 to the current char
	std::string result;
	for (int i = 0; i < input.length(); i++)
	{
		result += input[i] + 13;
	}
	return result;
}

std::string CryptoMachine::NonPalindromeEncrypt(std::string &input)
{
	std::string result;
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		result += (input[i] + i + length);
	}

	return result;
}

std::string CryptoMachine::PalindromeDecrypt(std::string &input)
{
	return std::string();
}

std::string CryptoMachine::NonPalindromeDecrypt(std::string &input)
{
	std::string result;
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		result += (input[i] - i - length);
	}

	return result;
}
