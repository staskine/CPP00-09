#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream> 
# include <iomanip>

class Contact {
    private :
        std::string firstname;
        std::string lastname;
        std::string nickname;
        std::string phonenumber;
        int index;
        std::string secret;

    public :
        void set_fname (std::string first) {
            firstname = first;
        }
        std::string get_fname() {
            return firstname;
        }
        void set_lname (std::string last) {
            lastname = last;
        }
        std::string get_lname() {
            return lastname;
        }
        void set_nname (std::string nick) {
            nickname = nick;
        }
        std::string get_nname() {
            return nickname;
        }
        void set_index(int i) {
            index = i;
        }
        int get_index() {
            return index;
        }
        void set_pnum(std::string first) {
            phonenumber = first;
        }
        std::string get_pnum() {
            return phonenumber;
        }
        void set_secret(std::string first) {
            secret = first;
        }
        std::string get_secret() {
            return secret;
        }
};

class PhoneBook {
    public :
        Contact contact[8];
};

int    print_contact(PhoneBook &phonebook);

#endif