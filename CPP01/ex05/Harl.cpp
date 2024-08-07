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
    void (Harl::*p[]) () =  {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string values[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4 && values[i].compare(level)) {
        i++;
    }
    if (i == 4) {
        std::cout << "Harl is upset you don't seem to know how to type" << std::endl;
        return ;
    }
    (this->*p[i]) ();
}

