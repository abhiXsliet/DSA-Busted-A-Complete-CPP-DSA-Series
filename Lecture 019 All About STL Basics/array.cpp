#include<iostream>
using namespace std;
//array data structure 
#include<array> //array's library



int main(){

    // simple/basic array declaration
    int basic[3] = {1, 2, 3};

    // array declaration using stl
    // stl array is declared using fixed size/static array that's why not used in cp
    array<int,4> a = {1, 2, 3, 4};

    int size = a.size();

    for(int i=0; i<size; i++){
        cout << a[i] << endl;
    }

    cout << "Element at 2nd index ==> " << a.at(2) << endl;

    cout << "Empty or not ==> " << a.empty() << endl;

    cout << "First Element ==> " << a.front() << endl;
    
    cout << "last Element ==> " << a.back() << endl;

    // a.at(index), a.front(), a.empty(), a.front(), a.back() -> Time Complexity = O(1)

    return 0;
} 