#include "Zombie.hpp"

int main() {
    try {
        Zombie* horde = zombieHorde(10, "Jack");
        for (int i = 0; i < 10; i++) {
            horde[i].announce();
        }
        delete[] horde;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}