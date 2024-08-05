#include "PhoneBook.hpp"

void Contact::set_fname (std::string first) {
    firstname = first;
}; 

std::string Contact::get_fname() {
    return firstname;
};

void Contact::set_lname (std::string last) {
    lastname = last;
};

std::string Contact::get_lname() {
    return lastname;
};

void Contact::set_nname(std::string nick) {
    nickname = nick;
};

std::string Contact::get_nname() {
    return nickname;
};

void Contact::set_index(int i) {
    index = i;
};

int Contact::get_index() {
    return index;
};

void Contact::set_pnum(std::string first) {
    phonenumber = first;
};

std::string Contact::get_pnum() {
    return phonenumber;
};

void Contact::set_secret(std::string first) {
    secret = first;
};

std::string Contact::get_secret() {
    return secret;
};
