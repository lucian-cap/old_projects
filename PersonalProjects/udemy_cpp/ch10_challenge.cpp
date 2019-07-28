#include <iostream>

using namespace std;

int main(){

    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    string decision {};


    while(true){
        cout << "Enter 1 to encrypt a message, and 2 to decrypt a message: ";

        getline(cin, decision);
        if(decision == "1" || decision == "2"){
            break;
        } else {
            cout << "I'm sorry that input wasn't recognized. Please enter either 1 or 2." << endl;
        }

    }

    if(decision == "1"){
        cout << "Please enter the message you wish to encrypt: \n";;
        string encrypt_message {};
        getline(cin, encrypt_message);

        string final {};

        for(char c : encrypt_message){
            if(alphabet.find(c) != string::npos){
                final += key.at(alphabet.find(c));
            } else{
                final += " ";
            }
        }
        cout << "Your encrypted message is: " << final << endl;
    } else{
        cout << "Please enter the encrypted message: ";
        string message {};
        getline(cin, message);

        string decrypted {};
        for(char c : message){
            if(key.find(c) != string::npos){
                decrypted += alphabet.at(key.find(c));
            } else{
                decrypted += " ";
            }
        }
        cout << "Your decrypted message is: " << decrypted << endl;
    }




    return 0;
}