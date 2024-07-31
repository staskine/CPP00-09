#include "phonebook.hpp"

void    print_arg(std::string str) {
    unsigned long i = 0;
    if (str.size() < 10) {
        std::cout << str;
        while (10 > (str.size() + i)) {
            std::cout << " ";
            i++;
        }
    }
    else {
        for (int x = 0; x < 9; x++) {
            std::cout << str[x];
        }
        std::cout << ".";
    }
}

void    print_contact(PhoneBook &phonebook) {
    int i = 0;
    std::string str = "12345678";
    std::string check;
    while (i < 8) {
        check = phonebook.contact[i].get_fname();
        if (check.size() == 0)
            break ;
        std::cout << str[i];
        for (int i = 0; i < 10; i++)
            std::cout << " ";
        std::cout << "|";
        print_arg(check);
        std::cout << "|";
        print_arg(phonebook.contact[i].get_lname());
        std::cout << "|";
        print_arg(phonebook.contact[i].get_nname());
        std::cout << "\n";
        i++;
    }
    while (1) {
        std::cout << "Pick an index to view info or 9 to leave : ";
        std::cin >> check;
        if (check.compare("9") == 0)
            return ;
        int i = std::stoi(check);
        if (i < 9 && i > 0)
            std::cout << "this was valid";
        else
            std::cout << "this was invalid";
    }
}
