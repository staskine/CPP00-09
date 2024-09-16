#include <iostream>
#include <ctype.h>

int main(int argc, char **argv)
{
    unsigned char c;
    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; argv[i]; i++)
    {
        std::string str = argv[i];
        for (unsigned long x = 0; x < str.size(); x++)
        {
            if (isalpha(str[x]))
                c = toupper(str[x]);
            else
                c = str[x];
            std::cout << c;
        }   
    }
    std::cout << '\n';
    return 0;
}
