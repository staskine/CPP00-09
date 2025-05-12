#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::saveDatabase(std::string const& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open data file." << std::endl;
        return false;
    }
    std::string line;
    std::getline(file, line);  // Skip header line
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
		std::string value;
        std::getline(ss, date, ',');
        std::getline(ss, value);
        float rate = std::stof(value);
        exchangeRates[date] = rate;
    }
    file.close();
    return true;
}

bool BitcoinExchange::processInput(std::string const& inputFile) {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return (false);
    }

    std::string line;
    while (std::getline(file, line)) {
		if (line == "date | value")
        	continue;
        std::string date;
		std::string valueStr;
        size_t separatorPos = line.find(" | ");
        if (separatorPos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        date = line.substr(0, separatorPos);
        valueStr = line.substr(separatorPos + 3);

		if (date.length() != 10 || !isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value)) {
            continue;
        }

        std::string closestDate;
        if (findClosestDate(date, closestDate)) {
            printResult(date, value, closestDate);
        } else {
            std::cerr << "Error: no valid date found for " << date << std::endl;
        }
    }
    file.close();
	return true;
}

bool BitcoinExchange::isValidDate(std::string const& date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    std::tm tm = {};
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");

    if (ss.fail())
        return false;

    // mktime normalizes tm structure — if invalid date was passed, it'll adjust it
    std::tm copy = tm;
    std::mktime(&tm);

    return (tm.tm_year == copy.tm_year && tm.tm_mon == copy.tm_mon && tm.tm_mday == copy.tm_mday);
}

bool BitcoinExchange::isValidValue(std::string const& valueStr, float& numericValue) {
	try {
        numericValue = std::stof(valueStr);
        if (numericValue < 0 || numericValue > 1000) {
            std::cerr << "Error: must be between 0 - 1000." << std::endl;
            return false;
        }
    } catch (...) {
        std::cerr << "Error: must be between 0 - 1000." << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::findClosestDate(std::string const& date, std::string& closestDate) {
    auto it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.begin()) {
        return false;
    }
    --it;
    closestDate = it->first;
    return true;
}

void BitcoinExchange::printResult(std::string const& date, float value, std::string const& closestDate) {
    float rate = exchangeRates.at(closestDate);
    std::cout << date << " => " << value << " = " << value * rate << std::endl;
}