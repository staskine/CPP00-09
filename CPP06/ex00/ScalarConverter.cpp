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
	if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << c << "\n";
	
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << i << std::endl;
	}

	std::cout << std::fixed << std::setprecision(1)<< "float: ";
	if (d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()) {
		std::cout << "impossible\n";
	} else {
		std::cout << f << "f" << std::endl;
	}

	std::cout << "double: ";
	if (!std::isfinite(d)) {
		std::cout << "impossible\n";
	} else {
		std::cout << d << std::endl;
	}
}

static char whatAmI(std::string argument)
{
	bool dot = false;
	for (size_t i = 0; i < argument.length(); i++) {
		char c = argument[i];
		if (isdigit(c))
			continue ;
		else if (i == 0 && (argument[i] == '-' || argument[i] == '+'))
			continue ;
		else if (c == '.' ) {
			if (dot == true || i == argument.length() - 1 || i == 0)
				return 'e';
			else 
				dot = true;
		}
		else if (c == 'f') {
			if (i != argument.length() - 1 || argument[i - 1] == '.')
				return ('e');
			else 
				return ('f');
		}
		else 
			return ('e');
	}
	if (dot == true)
		return ('d');
	return ('i');
}

void ScalarConverter::convert(std::string argument) {
	if (amISpecial(argument) == true)
			return ;
	if (argument.length() == 1 && !isdigit(argument[0])) {
		char c = argument[0];
		int i = static_cast<int>(c);
		float f = static_cast<float>(c);
		double d = static_cast<double>(c);
		printer(i, c, f, d);
	} else {
		char _me = whatAmI(argument); // i, f, d, e for error
		if (_me == 'e') {
			std::cout << "ERROR: Invalid input" << std::endl;
			return ;
		} else {
			std::cout << "Okay..." << std::endl;
		}
		// if (_me == 'i') {
		// 	handleInt(argument);
		// } else if (_me == 'f') {
		// 	handleFloat(argument);
		// } else
		// 	handleDouble(argument);

	}
}
