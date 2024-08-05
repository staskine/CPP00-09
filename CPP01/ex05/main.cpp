#include "Harl.hpp"

int main(int argc, char **argv) {
    try {
        if (argc != 2)
        {
            std::cerr << "Bro ;_:" << std::endl;
        }
        else
        {
            Harl harl;
            harl.complain(argv[1]);
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}