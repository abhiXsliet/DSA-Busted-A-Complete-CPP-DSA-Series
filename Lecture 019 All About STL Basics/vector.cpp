//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;



// It is a dynamic array
// But when the size becomes full it creates the new arrays of double size 
// and copy all elements of previous array into the newly made doubled size array and dump the previous array


#include<vector>

int main(){

    vector<int>v;          
    // capacity -> How much memory is assigned to array ?             
    cout << "Capacity-> " << v.capacity() << endl; 

    v.push_back(1);
    cout << "capacity-> " << v.capacity() << endl;

    v.push_back(2);
    cout << "capacity-> " << v.capacity() << endl;

    v.push_back(3);
    cout << "capacity-> " << v.capacity() << endl;

    // size -> total no. of elements present inside array
    cout << "size -> " << v.size() << endl;

    cout << "Element at 2nd index-> " << v.at(2) <<endl;

    cout << "front-> " << v.front() << endl;
    cout << "back-> " << v.back() << endl;
    
    cout << "before pop " << endl;
    for(int i:v){
        cout << i << " " ;
    }cout << endl;

    v.pop_back();
    for(int i:v){
        cout << i << " ";
    }cout << endl;

    //when we use .clear() operation on a vector 
    //then only the size of the vector becomes zero not the capacity(capacity of the vector remains the same as it is)

    cout << "before clear size-> " << v.size() << endl;
    v.clear();

    cout << "after clear size-> " << v.size() << endl;

    //by .begin() operation we can find the starting iterator;


    
    cout<<"\n" ;
    // 5 is the size of vector & initializing vector's(a) elements with 1
    vector<int> a(5,1); // other way of initializing a vector

    cout << "printing a => ";
    for(int i:a){
        cout << i << " ";
    }

    cout << endl << endl;

    // copying all elements of vector(a) into vector (last) 
    vector<int> last(a); 
    
    cout << "printing last => ";
    for(int i:last){
        cout << i << " ";
    }


    cout << endl << endl;
    vector<int> ans = {4, 5, 7, 8};
    auto it = lower_bound(ans.begin(), ans.end(), 6) ;
    if(it != ans.end()) {
        cout << "Lower bound " << *it << endl;
    } else {
        cout << "No lower bound found " << endl;
    }
    int x = lower_bound(ans.begin(), ans.end(), 6) - ans.begin();
    cout << x;

    cout << endl << endl;
    return 0;
}
