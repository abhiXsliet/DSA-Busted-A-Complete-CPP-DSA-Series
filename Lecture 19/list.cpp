//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;

//list 
#include<list>

//list stl is made using doubly linked list (it has two pointer one for front and other for back)

int main(){
    list<int> l;

    // copying list (l) into a new list (n)
    list<int> n(l); 

    // list has total 5-elements where every element initialized with 100
    list<int> ln(5,100); 
    
    cout << "\nprinting ln -> ";
    for(int i:ln){
        cout << i << " ";
    }cout << endl ;

    l.push_back(1);
    l.push_front(2);

    // l.pop_back();
    // l.pop_front();
    
    cout << "\nprinting push_back/front element -> ";
    for(int i:l){
        cout << i << " ";
    }

    cout << endl;

    l.erase(l.begin());
    cout << "after erase => " ;
    for(int i:l){
        cout << i << " ";
    }

    cout << "\nsize of list -> " << l.size() << endl;

    cout << endl;
    return 0;
}

