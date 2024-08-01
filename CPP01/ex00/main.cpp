#include "Zombie.hpp"

int main() {
    try {
        Zombie* stack = newZombie("Jack");
        randomChump("Jill");
        stack->announce();
        delete stack;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}