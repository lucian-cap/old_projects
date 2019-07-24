#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);
    cout << "vector1 position 0: " << vector1.at(0) << endl;
    cout << "vector1 position 1: " << vector1.at(1) << endl;
    cout << "vector1 has size of " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);
    cout << "vector2 position 0: " << vector2.at(0) << endl;
    cout << "vector2 position 1: " << vector2.at(1) << endl;
    cout << "vector2 has size of " << vector2.size() << endl;

    vector <vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "The element in vector2d at position 0, 0 are: " << vector_2d.at(0).at(0) << endl;
    cout << "The element in vector2d at position 0, 1 are: " << vector_2d.at(0).at(1) << endl;
    cout << "The elements in vector2d at position 1, 0 are: " << vector_2d.at(1).at(0) << endl;
    cout << "The element in vector2d at position 1, 1 are: " << vector_2d.at(1).at(1) << endl;

    vector1.at(0) = 1000;
    cout << "The element in vector2d after the change at position 0, 0 are: " << vector_2d.at(0).at(0) << endl;
    cout << "The element in vector2d after the change at position 0, 1 are: " << vector_2d.at(0).at(1) << endl;
    cout << "The element in vector2d after the change at position 1, 0 are: " << vector_2d.at(1).at(0) << endl;
    cout << "The element in vector2d after the change at position 1, 1 are: " << vector_2d.at(1).at(1) << endl;

    cout << "vector1 after change position 0: " << vector1.at(0) << endl;
    cout << "vector1 after change position 1: " << vector1.at(1) << endl;


    return 0;
}