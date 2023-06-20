#include<bits/stdc++.h>
using namespace std;


//Rough practice revising previous
class Human {
    int height2;

    public:
    int height;
    int weight;
    int age;

    int getAge() {
        cout << "you are inside getAge" << endl;
        return this->age;
    }

    int getWeight() {
        cout << "you are inside getWeight" << endl;
        return this->weight;
    }

    int getHeight() {
        cout << "you are inside getHeight " << endl;
        return this->height;
    }

    void setAge(int a) {
        cout << "you are inside setAge" << endl;
        this->age = a;
    }

    void setWeight(int w) {
        cout << "you are inside setWeight" << endl;
        this->weight = w;
    }

    void setHeight (int h) {
        cout << "you are inside setHeight" << endl;
        this->height = h;
    }


    int getHeight2(){
        cout << "you are inside getHeight2" << endl;
        return this->height2;
    }

    void setHeight2(int h) {
        cout << "you are inside setHeight2" << endl;
        this->height2 = h;
    }

    void printX() {
        cout << "you are inside printX" << endl;
        cout << this->height << endl;
        cout << this->age << endl;
        cout << this->weight << endl;
    }

    void print(){
        cout << "you are inside print" << endl;
        cout << this->height2 << endl;
        
    }
};

int main() {

    Human s;
    cout << s.height << endl;
    cout << s.weight << endl;
    cout << s.age << endl;

    cout << endl << endl;

    s.setAge(40);
    s.setHeight(5);
    s.setWeight(70);

    cout << s.height << endl;
    cout << s.weight << endl;
    cout << s.age << endl;
    cout << endl; 

    s.printX();
    
    cout << endl << endl;

    s.getHeight2();
    s.setHeight2(10);
    s.print();
    
    return 0;
}