#pragma once

# include <iostream>
# include <limits> 
# include <iomanip>
# include <cmath>

class ScalarConverter {
	public:
		static void convert(std::string argument);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter &operator=(const ScalarConverter& obj);
		~ScalarConverter();
};