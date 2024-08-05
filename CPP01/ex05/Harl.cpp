#include "Harl.hpp"

void Harl::debug(void) {
    std::cout << "Harl feels like you are being difficult. Stop or he will escalate." << std::endl;
};

void Harl::info(void) {
    std::cout << "You did not stop. He has now hurt his own feelings. Stop or he will escalate." << std::endl;
};

void Harl::warning(void) {
    std::cout << "Harl is getting annoyed. Give him something for free or he will escalate." << std::endl;
};

void Harl::error(void) {
    std::cout << "Harl is escalating. Run away or else." << std::endl;
};

void Harl::complain(std::string level) {
    std::string values[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && values[i].compare(level))
        i++;
    i++;
    switch (i) {
        case 1:
            this->Harl::debug();
            break ;
        case 2:
            this->Harl::info();
            break ;
        case 3:
            this->Harl::warning();
            break ;
        case 4:
            this->Harl::error();
            break ;
        default:
            std::cout << "Harl is upset you used invalid input" << std::endl;
    }
};

