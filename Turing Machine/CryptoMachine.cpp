#include "CryptoMachine.h"

const char alph[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
std::string CryptoMachine::PalindromeEncrypt(std::string& input) {

	std::string result;
	int size = input.length();
	for (int i = 0; i < input.length(); i++)
	{
		char a = input[i];
		
	}
}

std::string CryptoMachine::NonPalindromeEncrypt(std::string&)
{
	return std::string();
}

std::string CryptoMachine::PalindromeDecrypt(std::string&)
{
	return std::string();
}

std::string CryptoMachine::NonPalindromeDecrypt(std::string&)
{
	return std::string();
}
