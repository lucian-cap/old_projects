#include <iostream>

using namespace std;

int main(){

    int sum {0};

    for(int i {1}; i <= 15; i+=2){
        sum += i;
        cout << i << endl << sum << endl;
    }


    return 0;
}