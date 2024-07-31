#include "phonebook.hpp"

void    add_contact(Contact &contact, int i) {
    std::string input;
    std::cout << "Input first name : ";
    std::cin >> input; 
    contact.set_fname(input);
    std::cout << "Input last name : ";
    std::cin >> input;
    contact.set_lname(input);
    std::cout << "Input nickname : ";
    std::cin >> input;
    contact.set_nname(input);
    std::cout << "Input phone number : ";
    std::cin >> input;
    contact.set_pnum(input);
    std::cout << "Input darkest secret : ";
    std::cin >> input;
    contact.set_secret(input);
    contact.set_index(i);
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
            std::cin >> str;
            if (str.compare("ADD") == 0) {
                add_contact(phonebook.contact[i], i);
                if (i == 7)
                     i = 0;
                else
                    i++;
            }
            if (str.compare("SEARCH") == 0) {
                print_contact(phonebook);
            }
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
