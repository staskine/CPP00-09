#include "ScalarConverter.hpp"

//As this class doesn’t need to store anything at all, this class must not be instanciable by users.

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& obj) {(void)obj; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& obj) {
	(void)obj;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool amISpecial(std::string argument) {
	std::string specials[] = {"-inff", "+inff", "-inf", "+inf", "nan"};
	for (int i = 0; i < 5; i++) {
		if (argument == specials[i]) {
			std::cout << "char: impossible\nint: impossible\nfloat: " << argument << "f\ndouble: " << argument << std::endl;
			return true;
		}
	}
	return false;
}

static void printer(int i, char c, float f, double d) {
	std::cout << "char: "; 
	if (!isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << c << "\n";
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << i << std::endl;
	}
	std::cout << std::fixed << std::setprecision(1) << "float: " << f << "f\ndouble: " << d << std::endl; 
	
}

void ScalarConverter::convert(std::string argument) {
	if (amISpecial(argument) == true)
			return ;
	if (argument.length() == 1 && !isdigit(argument[0])) {
		char c = argument[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		std::cout << "char: " << c << "\nint: " << i << "\nfloat: " << f << "f\ndouble: " << d << std::endl;
	} else {
		std::cout << "Not found" << std::endl;
	}
}
