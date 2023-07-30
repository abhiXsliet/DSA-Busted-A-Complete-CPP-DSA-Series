#include <iostream>
using namespace std;


// Protected Class :- is kind of private
// You can access the protected class within the parent class 
// Protected class can be accessed by their child class or sub-class or Derived class 

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

class Male : protected Human {

    public: 
    string color;

    void sleep() {
        cout << "Male is sleeping" << endl;
    }

    int getHeight() {
        return this->height;
    }
};


class Male : private Human {
    public: 
    string color;

    void sleep() {
        cout << "Male is sleeping" << endl;
    }

    int getHeight() {
        return this->height;
    }
};


int main() {

    Male m1;
    cout << m1.getHeight() << endl;

    return 0;
}