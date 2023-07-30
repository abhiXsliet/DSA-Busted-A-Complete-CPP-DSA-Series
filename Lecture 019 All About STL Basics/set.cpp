//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;

//set
#include<set>

// Set stores unique element (e.g., inserting 5-times 4 will be stored only once in set);
// Modification in set is not possible, you can either insert, delete an element.
// Elements returned from set in sorted order
// Set is slow as compared to unordered set
// When we fetch elements from an unordered list then it returns into unordered form

int main(){
    
    //Time complexity of insert/ find/ erase or count => o(logn)
    //Time complexity of size/ end/ begin / empty => o(1)
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(auto i : s){
        cout << i << endl ;
    }cout << endl;

    set<int> :: iterator it = s.begin();
    it++;

    s.erase(it);

    for(auto i : s){
        cout << i << endl ;
    }cout << endl;

    cout << "-5 is present or not -> "<< s.count(-5) << endl;

    set<int> :: iterator itr = s.find(5);
    for(auto it = itr; it!=s.end(); it++){
        cout << *it << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}
