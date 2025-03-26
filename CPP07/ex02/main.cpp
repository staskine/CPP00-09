#include <iostream>
#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     std::cout << "I am running the test" << std::endl;
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }
//     //std::cout << "I'm going to print out the arguments" << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         //std::cout << "OG: " << numbers[i] << " and copy: " << mirror[i] << std::endl; 
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[0] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL - 1] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

int main() {
    try {
        std::cout <<  "Default constructor\n";
        Array<int> arr1;
        std::cout << "Size of arr1: " << arr1.size() << std::endl;

        std::cout <<  "\nConstructor with size\n";
        Array<int> arr2(5);
        std::cout << "Size of arr2: " << arr2.size() << std::endl;

        std::cout << "\nAccess elements and modify them\n";
        arr2[0] = 10;
        arr2[1] = 20;
        std::cout << "arr2[0]: " << arr2[0] << ", arr2[1]: " << arr2[1] << std::endl;

        std::cout << "\nCopy constructor\n";
        Array<int> arr3 = arr2;
        std::cout << "Size of arr3: " << arr3.size() << std::endl;
        arr3[0] = 99;
        std::cout << "arr3[0]: " << arr3[0] << ", arr2[0]: " << arr2[0] << std::endl;

        std::cout << "\nAssignment operator\n";
        Array<int> arr4;
        arr4 = arr2;
        std::cout << "Size of arr4: " << arr4.size() << std::endl;
        arr4[1] = 88;
        std::cout << "arr4[1]: " << arr4[1] << ", arr2[1]: " << arr2[1] << std::endl;

        std::cout << "\nTesting exception\n";
        std::cout << "Attempting to access out-of-bounds index..." << std::endl;
        std::cout << arr2[10] << std::endl; // Should throw an exception

    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}