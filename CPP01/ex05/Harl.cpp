#include <Harl.hpp>

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
    int i = level.stoi(level);
    switch (i) {
        case 1:
            *debug();
            break ;
        case 2:
            *info();
            break ;
        case 3:
            *warning();
            break ;
        case 4:
            *error();
            break ;
        default:
            std::cout << "Harl is upset you used invalid input" << std::endl;
    }
};

