#include <iostream>

using namespace std;

int main(){

    int dollars {0};
    int quarters {0};
    int dimes {0};
    int nickels {0};
    int pennies {0};

    int amount {0};

    cout << "Enter an amount in cents: ";
    cin >> amount;

    dollars = amount / 100;
    amount %= 100;
    
    quarters = amount / 25;
    amount %= 25;

    dimes = amount / 10;
    amount %= 10;

    nickels = amount / 5;
    amount %= 5;

    pennies = amount;

    cout << "\nYou can provide this change as follows:" << endl;
    cout << "dollars: " << dollars << endl << "quarters: " << quarters << endl << "dimes: " << dimes << endl << "nickels: " << nickels << endl << "pennies: " << pennies << endl;


    return 0;
}