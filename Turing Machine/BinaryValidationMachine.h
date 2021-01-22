#include <iostream>


class BinaryValidationMachine {
public:
	BinaryValidationMachine() {};

	static bool CheckIfContainsLetters(std::string& input) {
		bool doesContain = false;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] != '0' && input[i] != '1')
			{
				doesContain = true;
				break;
			}
		}

		return doesContain;
	};
};