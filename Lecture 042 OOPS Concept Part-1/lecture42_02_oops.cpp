#include<iostream>
#include "lecture42_01_oops.cpp" //class
using namespace std;

int main() {

    //creation of object
    Hero ramesh;
    
    ramesh.health = 5;
    ramesh.level = 'A';

    cout << "Health is : " << ramesh.health << endl;
    cout << "Level is : " << ramesh.level << endl;

    cout << endl;
    return 0;
}