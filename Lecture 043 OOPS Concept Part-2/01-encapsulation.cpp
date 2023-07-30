#include<bits/stdc++.h>
using namespace std;

// Encapsulation :- is wrapping of data members and fuctions in a single entity. data members and functions are generally known as properties/state and methods/behaviours respectively
// information hiding or data hiding whenever encapsulation came into play

// when one can successfully wrapped the data members and fuctions in a single entity then we can say that encapsulation is achieved.
// capsule --> is class

// fully encapsulated class :- all data membes are private marked (same class me hi access kar payenge)

// why? encapusulation 
// Advantage => 1. we can hide the data => security increases
//             2. If we want, we can mark class - "Read only"
//             3. code resuability
//             4. encapsulation helps in unit testing




class student {

    private:
        string name;
        int age;
        int height;

    public:
    //encapsulation achieved 

        int getAge() {
            return this -> age;
        }

};

int main() {
    
    student first;
    
    cout << endl;
    return 0;
}