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

int    print_contact(PhoneBook &phonebook) {
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
        std::getline(std::cin, check);
        if (std::cin.eof()) {
            std::cout << "DONT PRESS CTRL + D" << std::endl;
            return 1;
        }
        if (check.size() == 0)
            continue ;
        if (check.compare("9") == 0)
            return 0;
        if (check.size() == 1 && isdigit(check[0]) != 0) {
            int i = std::stoi(check) - 1;
            std::string check = phonebook.contact[i].get_fname();
            if (check.size() == 0) {
                std::cout << "This index is empty";
                continue ;
            }
            std::cout << "First name : " << check << "\n";
            std::cout << "Last name : " << phonebook.contact[i].get_lname() << "\n";
            std::cout << "Nickname : " << phonebook.contact[i].get_nname() << "\n";
            std::cout << "Phone Number : " << phonebook.contact[i].get_pnum() << "\n";
            std::cout << "Darkest Secret : " << phonebook.contact[i].get_secret() << "\n";
            i++;
        }
        else
            std::cout << "this was invalid\n";
    }
    return 0;
}
