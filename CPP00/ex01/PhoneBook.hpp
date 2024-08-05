#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream> 
# include <iomanip>
# include "Contact.hpp"

class PhoneBook {
    public :
        Contact contact[8];
};

int    print_contact(PhoneBook &phonebook);

#endif
