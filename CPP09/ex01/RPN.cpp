#include "RPN.hpp"

// How RPN works
// RPN works by using a stack. Here's how you'd evaluate 3 4 2 * +:
// Read 3 → push to stack → stack: [3]
// Read 4 → push to stack → stack: [3, 4]
// Read 2 → push to stack → stack: [3, 4, 2]
// Read * → pop two numbers: 4 and 2, compute 4 * 2 = 8, push 8 → stack: [3, 8]
// Read + → pop two numbers: 3 and 8, compute 3 + 8 = 11, push 11 → stack: [11]
// Final result: 11

void	calculator(const std::string& input) {
	std::stack<int> myStack;
	std::istringstream stream(input);
	std::string arg;

	while (stream >> arg) {
		if (arg.size() != 1) {
			std::cerr << "Error" << std::endl;
			return ;
		}
		if (isdigit(arg[0])) {
			myStack.push(std::stoi(arg));
		} else {
			if (myStack.size() > 1 && (arg == "+" || arg == "-" || arg == "/" || arg == "*")) {
				long long top = myStack.top(); myStack.pop();
            	long long second = myStack.top(); myStack.pop();
				long long result;
				if (arg == "+") {
					result = second + top;
				} else if (arg == "-") { 
					result = second - top; 
				} else if (arg == "*") {
				 	result = second * top;
				} else if (arg == "/" && top != 0) { 
					result = second / top; 
				} else {
					std::cerr << "Error" << std::endl;
					return ;
				}
				if (result >= std::numeric_limits<int>::min() && result <= std::numeric_limits<int>::max()) {
					int i = static_cast<int>(result);
					myStack.push(i);
				} else {
					std::cerr << "Error: arithmetic overflow" << std::endl;
					return ;
				}
			}
			else {
				std::cerr << "Error" << std::endl;
				return ;
			}
		}
	}
	if (myStack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return ;
	} else {
		std::cout << myStack.top() << std::endl;
	}
}