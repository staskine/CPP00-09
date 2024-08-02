#include "SedIsForLosers.hpp"

int main(int argc, char **argv) {
    try {
        if (argc != 4)
        {
            std::cout << "Put in three arguments" << std::endl;
        }
        else {
            std::string line = ".replace";
            if (std::filesystem::exists(argv[1] + line)) {
                std::cout << "The .replace file already exists" << std::endl;
                return 1;
            }
            char temp;
            std::string buf;
            std::ifstream inFile(argv[1]);
            if (inFile.is_open()) {
                while (!inFile.eof() && inFile >> std::noskipws >> temp) {
                   buf += temp;
                }
            }
            else {
                std::cerr << "Could not open file" << std::endl;
                return 1;
            }
            inFile.close();
            std::string s1 = argv[2];
            std::string s2 = argv[3];
            size_t found = buf.find(s1);
            while (found != std::string::npos) {
                buf.erase(found, s1.size());
                buf.insert(found, s2);
                found = buf.find(argv[2]);
            }
            
            std::ofstream outFile(argv[1] + line);
            if (!outFile) {
                std::cerr << "Could not make outfile" << std::endl;
                return 1;
            }
            outFile << buf;
            outFile.close();
            
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}


//.find
//.erase sizeof str1
//.insert