#pragma once

# include <iostream>
# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <ctime>
# include <iomanip>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();

    bool loadDatabase(const std::string& filename); 
    bool processInput(const std::string& inputFile);

private:
    std::map<std::string, float> exchangeRates;
    bool isValidDate(const std::string& date);
    bool isValidValue(const std::string& value, float& numericValue);
    bool findClosestDate(const std::string& date, std::string& closestDate);
    void printResult(const std::string& date, float value, const std::string& closestDate);
};
