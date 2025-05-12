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

    bool saveDatabase(std::string const& filename); 
    bool processInput(std::string const& inputFile);

private:
    std::map<std::string, float> exchangeRates;
    bool isValidDate(std::string const& date);
    bool isValidValue(std::string const& value, float& numericValue);
    bool findClosestDate(std::string const& date, std::string& closestDate);
    void printResult(std::string const& date, float value, std::string const& closestDate);
};
