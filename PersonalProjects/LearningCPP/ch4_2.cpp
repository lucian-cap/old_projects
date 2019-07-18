#include <fstream>
#include <iostream>

using namespace std;

int main(){

    ifstream input;
    ofstream output;
    char temp;
    input.open("quote.txt");
    output.open("upquote.txt");


    //Not sure why, but toupper for me returns an int
    //and not another char like the book, probably
    //due to the version of C++ I've got
    input >> temp;
    output << (char)toupper(temp) << " ";
    input >> temp;
    output << (char)toupper(temp) << " ";
    input >> temp;
    output << (char)toupper(temp) << " ";
    input >> temp;
    output << (char)toupper(temp) << " ";
    input >> temp;
    output << (char)toupper(temp) << " ";
    input >> temp;
    output << (char)toupper(temp) << " ";

    input.close();
    output.close();
    return 0;
}