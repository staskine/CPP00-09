#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "PhoneBook.hpp"

class Contact {
    private :
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        int index;
        std::string secret;

    public :
        void set_fname (std::string first);
        std::string get_fname();
        void set_lname(std::string last);
        std::string get_lname();
        void set_nname (std::string nick);
        std::string get_nname();
        void set_index(int i);
        int get_index();
        void set_pnum(std::string first);
        std::string get_pnum();
        void set_secret(std::string first);
        std::string get_secret();
};

#endif
