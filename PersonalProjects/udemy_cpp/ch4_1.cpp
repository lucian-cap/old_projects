#include <iostream>

int main(){
    int favNum;
    std::cout << "Please enter your favorite number between 1 and 100: ";
    std::cin >> favNum;
    std::cout << "Wow! " << favNum << " is my favorite number too!" << std::endl;
    return 0;
}