//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;
 
//map (44:00)
#include<map>

// Same key can't point to two different values
// Sorted in map but random in unordered map

int main(){
    map<int,string> m;

    // 1 is key and sharma is value
    m[1] = "sharma"; 
    m[13] = "kumar";
    m[2] = "abhishek";

    // other way of inserting
    m.insert( {5, "bheem"}); 

    cout << "\nBefore erase:- " << endl;
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }

    cout << "\nfinding 13 -> " << m.count(13) << endl;
    cout << "finding -13 -> " << m.count(-13) << endl;

    // m.erase(13);
    cout << "\nAfter erase:-" << endl;
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    cout << endl ;
    auto it = m.find(5);
    for(auto i = it; i!=m.end(); i++){
        cout << (*i).first << endl;
    }

    // Time complexity of insert/erase/find/count => o(logn);
    // Time complexity of search => o(logn) since stl map is implemented using binary tree  
    // O(1) in unordered map because stl map is implemented by using hash table


}