#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Please give one argument" << std::endl;
		return 1;
	}
	std::cout << "This was your argument: |" << argv[1] << "|" << std::endl;
	ScalarConverter::convert(argv[1]);
}