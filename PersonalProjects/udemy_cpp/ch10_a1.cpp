#include <iostream>

using namespace std;

int main(){

    cout << "Please enter your message for the Letter Pyramid: " << endl;
    string message {};
    getline(cin, message);

    for(int i {0}; i < message.size(); i++){
        string temp = message.substr(0, i);
        string output {};
        for(int ix = 0; ix < i; ix++){
            output += temp.at(ix);
        }
        output += message.at(i);
        for(int ix = temp.size() - 1; ix >= 0; ix--){
            output += temp.at(ix);
        }

        int final_size = (message.size() - 1) * 2 + 1;

        for(int ix {0}; ix < (final_size-output.size()) / 2; ix++){
            cout << " ";
        }
        cout << output;
        for(int ix {0}; ix < (final_size - output.size())/2; ix++){
            cout << " ";
        }

        cout << endl;

    }





    return 0;
}