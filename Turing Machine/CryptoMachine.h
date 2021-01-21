#include "iostream"
class CryptoMachine {
public: 
	static std::string PalindromeEncrypt(std::string&);
	static std::string NonPalindromeEncrypt(std::string&);
	
	static std::string PalindromeDecrypt(std::string&);
	static std::string NonPalindromeDecrypt(std::string&);
};