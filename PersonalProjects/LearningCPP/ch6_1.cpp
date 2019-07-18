#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ifstream input;
    float score, total, grade;
    string name;

    input.open("ch6_1.txt");

    cout << setprecision(5);
    while(input){
        input >> name >> score >> total;
        grade = score/total;
        cout << name << " " << ceil((grade*100)) << "% " << grade << " ";
        if (ceil(grade*100) > 90)
            cout << "Excellent" << endl;
        else if (ceil(grade*100) > 80)
            cout << "Well Done" << endl;
        else if (ceil(grade*100) > 70)
            cout << "Good" << endl;
        else if (ceil(grade*100) > 60)
            cout << "Need Improvement" << endl;
        else 
            cout << "Fail" << endl;
    }

    input.close();
    
    
    return 0;
}