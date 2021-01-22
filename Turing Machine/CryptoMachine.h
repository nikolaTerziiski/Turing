#include "iostream"
#include "Node.h"
#include "Machine.h"

class CryptoMachine : Machine {
	private:
		void PalindromeCrypting();
		void NonPalindromeCrypting(std::string& text);
		void Initialize(std::string& text);
		void Encrypt(std::string& text, bool isPalindrome);

	public: 
		CryptoMachine() {
			iterator = first = nullptr;
		}
		CryptoMachine(std::string& text, bool isPalindrome) {
			this->Initialize(text);
			this->refresh();
			this->Encrypt(text, isPalindrome);
		}

		~CryptoMachine() {
			if (this->first->data)
			{
				delete[] this->first->prev;
				delete[] this->first->next;
				delete[] this->first;
				this->first = nullptr;
			}
			else
			{
				delete[] this->first;
			}
		}
	
};