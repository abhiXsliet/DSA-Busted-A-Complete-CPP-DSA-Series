#include<bits/stdc++.h>
using namespace std;

// INHERITANCE
// Inheriance is the property of inherit from its parent/super class to the sub-class or child class

// Types of Inheritance;
// 1. Single
// 2. Multi-level
// 3. Multiple (multipath)
// 4. Hybrid
// 5. Hierarchical


//while inheritaning keep in mind this table
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////            ------- TABLE -------             ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////    superclass/parent class ---  inheritance mode   ---   after inheritance      //////////////////
///////////                                                                                 //////////////////
///////////     1. public              ---      public         ---      public              //////////////////
///////////     2. public              ---      private        ---      private             //////////////////
///////////     3. public              ---      protected      ---      protected           //////////////////
///////////                                                                                 //////////////////
///////////     4. protected           ---      public         ---      protected           //////////////////
///////////     5. protected           ---      private        ---      private             //////////////////
///////////     6. protected           ---      protected      ---      protected           //////////////////
///////////                                                                                 //////////////////
///////////     7. private             ---      public         ---      N/A                 //////////////////             
///////////     8. private             ---      private        ---      N/A                 //////////////////
///////////     9. private             ---      protected      ---      N/A                 //////////////////
///////////                                                                                 //////////////////
///////////     *** private marked class can not be accessed by any mode ***                //////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Human {
    
    public:
        int height;
        int weight;
        int age;

    public:
        int getAge() {
            return this->age;
        }

        void setWeight(int w) {
            this -> weight = w;
        }

};

// synatx => class childClass : mode parentClass

// for parent class (i.e, Human), Male is a child class
class Male : public Human {

    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }
};

int main() {

    Male object1;

    //inheriting from the parent class
    cout << object1.height << endl; //filled with garbage value
    cout << object1.weight << endl; //filled with garbage value
    cout << object1.age << endl;    //filled with garbage value

    cout << object1.color << endl;  //filled with garbage value
    
    object1.setWeight(84);
    cout << object1.weight << endl;

    object1.sleep();

    cout << endl;
    return 0;
}