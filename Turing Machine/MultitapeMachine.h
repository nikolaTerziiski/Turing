#include <iostream>
#include <vector>
#include "Node.h"
#include "Machine.h"

class MultitapeMachine {
private:
	std::vector<Node> nodes;

	void transform();
public:
	MultitapeMachine() {};
	MultitapeMachine(std::vector<Node>& tapes) {
		this->nodes = tapes;
	}
};
