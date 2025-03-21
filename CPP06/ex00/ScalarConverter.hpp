#pragma once

# include <iostream>
# include <limits> 
# include <iomanip>
# include <cmath>
# include <cctype>
# include <regex>
# include <stdexcept>

class ScalarConverter {
	public:
		static void convert(std::string argument);

	private:
		ScalarConverter &operator=(const ScalarConverter& obj);
		~ScalarConverter();
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
};