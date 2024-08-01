#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name) {
    Zombie *stack = new Zombie[N];
    for (int i = 0; i < N; i++) {
        stack[i].setname(name);
    }
    return stack;
}