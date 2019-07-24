#include <iostream>

using namespace std;

int main(){
    const double PRICE_LARGE_ROOM {35};
    const double PRICE_SMALL_ROOM {25};
    const double TAX_RATE {6};
    const int ESTIMATE_RANGE {30};

    cout << "Hello, welcome to Frank's Carpet Cleaning Service" << endl << endl;

    int small {0};
    int large {0};
    cout << "How many small rooms would you like cleaned? ";
    cin >> small;
    cout << "How many large rooms would you like cleaned? ";
    cin >> large;

    cout << endl << "Estimate for carpet cleaning service:" << endl;
    cout << "Number of small rooms: " << small << endl;
    cout << "Number of large rooms: " << large << endl;
    cout << "Price per small room: $" << PRICE_SMALL_ROOM << endl;
    cout << "Price per large room: $" << PRICE_LARGE_ROOM << endl;
    
    double cost = (PRICE_LARGE_ROOM * large) + (PRICE_SMALL_ROOM * small);
    cout << "Cost: $" << cost << endl;
    
    double tax = cost * (TAX_RATE/100);
    cout << "Tax: $" << tax << endl << "==============================" << endl;

    cout << "Total Estimate: $" << (cost + tax) << endl;
    cout << "This estimate is valid for " << ESTIMATE_RANGE << " days." << endl << endl;

    return 0;
}