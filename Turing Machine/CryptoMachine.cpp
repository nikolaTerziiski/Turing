#include "CryptoMachine.h"

//const char alph[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
//std::string CryptoMachine::PalindromeEncrypt(std::string& input) {
//
//	//Basic transformation of the string. Just adding 13 to the current char
//	std::string result;
//	for (int i = 0; i < input.length(); i++)
//	{
//		result += input[i] + 13;
//	}
//	return result;
//}
//
//std::string CryptoMachine::NonPalindromeEncrypt(std::string &input)
//{
//	std::string result;
//	int length = input.length();
//	for (int i = 0; i < length; i++)
//	{
//		result += (input[i] + i + length);
//	}
//
//	return result;
//}
//
//std::string CryptoMachine::PalindromeDecrypt(std::string &input)
//{
//	return std::string();
//}
//
//std::string CryptoMachine::NonPalindromeDecrypt(std::string &input)
//{
//	std::string result;
//	int length = input.length();
//	for (int i = 0; i < length; i++)
//	{
//		result += (input[i] - i - length);
//	}
//
//	return result;
//}

void CryptoMachine::moveLeft() {
	iterator = iterator->prev;
}
void CryptoMachine::moveRight() {
	iterator = iterator->next;
}

void CryptoMachine::refresh()
{
	this->iterator = first->next;
}


void CryptoMachine::PalindromeCrypting()
{
	while (iterator->next != nullptr)
	{
		iterator->data = iterator->data + 13;
		this->moveRight();
	}
}

void CryptoMachine::NonPalindromeCrypting(std::string& input)
{
	int length = input.length();
	for (int i = 0; i < length; i++)
	{
		iterator->data += (length * 2 - (i + 2));
		moveRight();
	}
}

void CryptoMachine::Initialize(std::string& text)
{
	Node* q;
	iterator = new Node;

	//Declaration of iterator
	iterator->prev = iterator->next = nullptr;
	first = iterator;
	for (int i = 0; i < text[i] != '\0'; i++)
	{
		q = new Node;
		q->prev = iterator;
		q->next = nullptr;
		q->data = text[i];
		iterator->next = q;
		iterator = q;
	}

	iterator->next = new Node();
	iterator->next->prev = iterator;
	iterator->next->data = NULL;

	iterator = first;
}

void CryptoMachine::Encrypt(std::string& text, bool isPalindrome)
{

	if (isPalindrome)
		this->PalindromeCrypting();
	else
		this->NonPalindromeCrypting(text);
}

void CryptoMachine::Print()
{
	this->iterator = this->first->next;
	while (iterator->next != nullptr)
	{
		std::cout << iterator->data;
		moveRight();
	}
}
