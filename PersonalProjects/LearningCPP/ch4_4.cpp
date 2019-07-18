#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

    ofstream output;
    float prevNum, curNum, total = 0;

    //open file to write to, get 1st and 2nd nums
    output.open("tempdata.dat");
    cin >> prevNum >> curNum;
    total = prevNum + curNum;

    //write 1st num to file, get 2nd num into prev
    output << prevNum << endl;
    prevNum = curNum;

    //get 3rd num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 4th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 5th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 6th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 7th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 8th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 9th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 10th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 11th num, increase total, write to file and switch positions
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    prevNum = curNum;

    //get 12th num, increase total, write to file, then
    cin >> curNum;
    total += curNum;
    output << prevNum << ' ' << (prevNum - curNum) << endl;
    output << curNum << endl;

    output.close();
    cout << (total / 12) << endl;



    return 0;
}