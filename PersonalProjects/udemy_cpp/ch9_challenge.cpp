#include <iostream>
#include <vector>
#include <cctype>


using namespace std;

int main(){

    vector<int> list;
    char choice;
    bool loop = true;

    while (true){

        cout << "P - Print numbers \nA - Add a number \nM - Display mean of the numbers \nS - Display the smallest number \nL - Display the largest number \nQ - Quit \n\nEnter your choice: ";
        cin >> choice;

        choice = toupper(choice);

        switch (choice){
            case 'P': 
                if (list.size() == 0){
                    cout << "[] - the list is empty" << endl;
                } else{
                    cout << "[";
                    for (int i {0}; i < list.size(); i++){
                        cout << " " << list.at(i);
                    }
                    cout << " ]" << endl;
                }
                break;
            case 'A':{
                cout << "What number would you like to add to the list: ";
                int new_num {0};
                cin >> new_num;
                list.push_back(new_num);
                cout << new_num << " added." << endl;
                break;}
            case 'M':{
                if(list.size() == 0){
                    cout << "Unable to calculate the mean - no data" << endl;
                } else {
                    double mean {0};
                    for(int i {0}; i < list.size(); i++){
                        mean += list.at(i);
                    }
                    mean = mean/list.size();
                    cout << "The mean of the list is " << mean << endl;
                }
                break;}
            case 'S':{
                if (list.size() == 0){
                    cout << "Unable to determine the smallest number - list is empty" << endl;
                } else {
                    int small {0};
                    for(int i {0}; i < list.size(); i++){
                        if (list.at(i) < small){
                            small = list.at(i);
                        }
                    }
                    cout << "The smallest number in the list is " << small << endl;
                }
                break;}
            case 'L':{
                if(list.size() == 0){
                    cout << "Unable to determine the largest number - the list is empty" << endl;
                } else {
                    int large {0};
                    for (int i {0}; i < list.size(); i++){
                        if (list.at(i) > large)
                            large = list.at(i);
                    }
                    cout << "The largest number in the list is " << large << endl;
                }
                break;}
            case 'Q':
                cout << "Goodbye" << endl;
                loop = false;
                break;
            default:
                cout << "Unknown selection, please try again";
        }

        cout << endl << endl;

        if(loop == false){
            break;
        }




    }


    return 0;
}