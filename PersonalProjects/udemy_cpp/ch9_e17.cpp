#include <iostream>
#include <vector>

using namespace std;

int main(){


    vector<int> vec;

    int result{0};

    for (int i {0}; i < vec.size() - 1; i++){
        for(int ix {i+1}; ix < vec.size(); ix++){
            result += vec.at(i) * vec.at(ix);
        }
    }

    cout << result << endl;


    return 0;
}