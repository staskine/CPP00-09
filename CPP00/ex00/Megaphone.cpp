#include <iostream>

int main(int argc, char **argv)
{
    char c;
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; argv[i]; i++)
    {
        std::string str = argv[i];
        for (unsigned long x = 0; x < str.size(); x++)
        {
            c = toupper(argv[i][x]),
            std::cout << c;
        }   
    }
    std::cout << '\n';
    return 0;
}