#include <iostream>
#include <string>

using namespace std;

int main(){

    string first, middle, last;
    int pos;

    cout << "Please enter your first, middle, and last name in the following format: 'last, first middle': " << endl;
    cin >> last >> first >> middle;
    pos = last.find(",");
    cout << "Your name re-formatted is " << first << ' ' << middle << ' ' << last.substr(0, pos) << endl;


    return 0;
}