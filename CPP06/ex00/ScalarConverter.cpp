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

static bool amIOkay(std::string input)
{
	std::regex myRegex(R"(^\d+(\.\d+)?f?$)"); 
    return std::regex_match(input, myRegex);
}

static char whatAmI(std::string argument)
{
	if (amIOkay(argument) == false)
		return 'e';
	bool dot = false;
	for (size_t i = 0; i < argument.length(); i++) {
		char c = argument[i];
		if (c == 'f')
			return 'f';
		if (c == '.')
			dot = true;
	}
	if (dot)
		return ('d');
	return ('i');
}

static void handleInt(const std::string& input) {
    int intValue;
    float floatValue;
    double doubleValue;
    char charValue;

    // Try to convert string to int
    try {
        intValue = std::stoi(input);
    } catch (const std::exception&) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // Convert int to char
    if (intValue < std::numeric_limits<char>::min() || intValue > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible\n";
    } else if (std::isprint(static_cast<char>(intValue))) {
        charValue = static_cast<char>(intValue);
        std::cout << "char: '" << charValue << "'\n";
    } else {
        std::cout << "char: Non displayable\n";
    }

    // Print int
    std::cout << "int: " << intValue << "\n";

    // Convert to float and double
    try {
        floatValue = std::stof(input);
        doubleValue = std::stod(input);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f\n";
        std::cout << "double: " << doubleValue << "\n";
    } catch (const std::exception&) {
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

static void handleFloat(const std::string& input) {
    int intValue;
    float floatValue;
    double doubleValue;
    char charValue;

    // Try to convert string to int
    try {
        intValue = std::stoi(input);
    } catch (const std::exception&) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // Convert int to char
    if (intValue < std::numeric_limits<char>::min() || intValue > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible\n";
    } else if (std::isprint(static_cast<char>(intValue))) {
        charValue = static_cast<char>(intValue);
        std::cout << "char: '" << charValue << "'\n";
    } else {
        std::cout << "char: Non displayable\n";
    }

    // Print int
    std::cout << "int: " << intValue << "\n";

    // Convert to float and double
    try {
        floatValue = std::stof(input);
        doubleValue = std::stod(input);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f\n";
        std::cout << "double: " << doubleValue << "\n";
    } catch (const std::exception&) {
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

void handleDouble(const std::string& input) {
    double doubleValue;
    int intValue;
    float floatValue;
    char charValue;

    // Try to convert string to double
    try {
        doubleValue = std::stod(input);
    } catch (const std::exception&) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    // Convert double to int
    if (doubleValue < std::numeric_limits<int>::min() || doubleValue > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible\n";
    } else {
        intValue = static_cast<int>(doubleValue);
        std::cout << "int: " << intValue << "\n";
    }

    // Convert int to char (only if int conversion was valid)
    if (doubleValue < std::numeric_limits<char>::min() || doubleValue > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible\n";
    } else if (std::isprint(static_cast<char>(intValue))) {
        charValue = static_cast<char>(intValue);
        std::cout << "char: '" << charValue << "'\n";
    } else {
        std::cout << "char: Non displayable\n";
    }

    // Convert double to float
    if (doubleValue < -std::numeric_limits<float>::max() || doubleValue > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible\n";
    } else {
        floatValue = static_cast<float>(doubleValue);
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << floatValue << "f\n";
    }

    // Print double
    std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << doubleValue << "\n";
}

void ScalarConverter::convert(std::string argument) {
	if (amISpecial(argument) == true)
			return ;
	if (argument.length() == 1 && !std::isdigit(argument[0])) {
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
		} else if (_me == 'i') {
			handleInt(argument);
		} else if (_me == 'f') {
			handleFloat(argument);
		} else if (_me == 'd' ) {
			handleDouble(argument);
		}
	}
}
