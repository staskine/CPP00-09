#include "PhoneBook.hpp"

int    add_contact(Contact &contact, int i) {
    std::string input;
    while (input.size() == 0) {
        std::cout << "Input first name : ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "DONT PRESS CTRL + D" << std::endl;
            return 1;
        }
    }
    contact.set_fname(input);
    input = "";
    while (input.size() == 0) {
        std::cout << "Input last name : ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "DONT PRESS CTRL + D" << std::endl;
            return 1;
        }
    }
    contact.set_lname(input);
    input = "";
    while (input.size() == 0) {
        std::cout << "Input nickname : ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "DONT PRESS CTRL + D" << std::endl;
            return 1;
        }
    }
    contact.set_nname(input);
    input = "";
    while (input.size() == 0) {
        std::cout << "Input phone number : ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "DONT PRESS CTRL + D" << std::endl;
            return 1;
        }
    }
    contact.set_pnum(input);
    input = "";
    while (input.size() == 0) {
        std::cout << "Input darkest secret : ";
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "DONT PRESS CTRL + D" << std::endl;
            return 1;
        }
    }
    contact.set_secret(input);
    contact.set_index(i);
    return 0;
}

int main()
{
    try {
        PhoneBook phonebook;
        int i = 0;
    
        std::string str;
        while (str.compare("EXIT"))
        {
            std::cout << "COMMANDS ARE\n1.ADD: save a new contact\n" << "2.SEARCH: display a specific contact\n" << "3.EXIT" << std::endl;
            std::getline(std::cin, str);
            if (std::cin.eof() == 1) {
                std::cout << "DONT PRESS CTRL + D" << std::endl;
                std::cin.clear();
                break ;
            }
            if (str.compare("ADD") == 0) {
                if (add_contact(phonebook.contact[i], i) > 0)
                    break ;
                if (i == 7)
                     i = 0;
                else
                    i++;
            }
            else if (str.compare("SEARCH") == 0) {
                if (print_contact(phonebook) != 0)
                    break ;
            }
        }
        std::cout << "Thank you for using this phonebook\n" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
