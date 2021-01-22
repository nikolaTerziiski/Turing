#include "CryptoMachine.h"

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