#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ifstream input;
    float score;
    float total;
    float percentTotal;
    input.open("ch4_1.txt");

    input >> score >> total;
    percentTotal = ceil((score/total)*100);


    cout << "The grade as a percent is " << percentTotal << "%" << endl;
    cout << setprecision(5) << "The grade as a decimal (up to 5 places after the '.') is " << (score/total) << endl;
    
    
    input.close();
    return 0;
}