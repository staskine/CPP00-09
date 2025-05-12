#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: need two arguments." << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    if (!btc.saveDatabase("data.csv"))
        return 1;
    if (!btc.processInput(argv[1]))
        return 1;
    return 0;
}