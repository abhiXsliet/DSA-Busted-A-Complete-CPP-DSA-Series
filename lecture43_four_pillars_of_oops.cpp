#include<bits/stdc++.h>
using namespace std;

//Encapsulation :- is wrapping of data members and fuctions in a single entity. data members and functions are generally known as properties/state and methods/behaviours respectively
//information hiding or data hiding whenever encapsulation came into play

//when one can successfully wrapped the data members and fuctions in a single entity then we can say that encapsulation is achieved.
//capsule --> is class

//fully encapsulated class :- all data membes are private marked (same class me hi access kar payenge)

//why? encapusulation 
//Advantage => 1. we can hide the data => security increases
//             2. If we want, we can mark class - "Read only"
//             3. code resuability
//             4. encapsulation helps in unit testing

//refers code studio documentation

/* 
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
    
}

 */



//INHERITANCE
//inheriance is the property of inherit from its parent/super class to the sub-class or child class



//while inheritaning keep in mind this table (watch at 22:00)
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

/* 

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

//synatx => class childClass : mode parentClass


//for parent class (i.e, Human), Male is a child class
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

    return 0;
}

 */


//protected class :- is kind of private
//you can access the protected class within the parent class 
//protected class can be accessed by their child class or sub-class or Derived class 
/* 

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


 */

//Types of Inheritance;
//1. Single
//2. Multi-level
//3. Multiple (multipath)
//4. Hybrid
//5. Hierarchical



//from class A, class B is inheriting => single inheritance
//class Male is inheriting their properties from class Human 
/* 
class Animal {
    public:

    int age;
    int weight;

    public:
    void speak() {
        cout << "speaking " << endl;
    }
};

class Dog : public Animal {

};

int main() {

    Dog d;
    d.speak();
    cout << d.age << endl;

    return 0;
}

 */



// class A => class B => class C => class D => class E
//Here class B is inheriting its properties from class A, and class C is inheriting its properties from class B and so on. 
//this type of inheritance is considered as the multi-level inheritance
/* 

class Animal {
    public:

    int age;
    int weight;

    public:
    void speak() {
        cout << "speaking " << endl;
    }
};

class Dog : public Animal {

};

class GermaShephard : public Dog {

};


int main() {
    
    //multi-level inheritance
    Dog d;
    d.speak();
    cout << d.age << endl;

    return 0;
}


 */




//Multiple Inheritance
//class A , class B => class C
//Here, class C is inheriting from the both classes: class A and class B

/* 
class Animal {

    public:
    int age;
    int weight;

    public:
    void bark() {
        cout << "Barking " << endl;
    }

};


class Human {

    public:
    string color;

    public:
    void speak() {
        cout << "Speaking " << endl;
    }
};

//multiple inheritance
class Hybrid : public Animal, public Human {

};

int main() {

    Hybrid object1;
    object1.speak();
    object1.bark();

    return 0;
}

 */


/* 
//Hierarchical inheritance;
//one class serves as a parent class for more than one class;


class A {

    public:
    void func1() {
        cout << "Inside function 1" << endl;
    }
};

class B : public A {

    public:
    void func2() {
        cout << "Inside function 2" << endl;
    }
};

class C : public A {

    public:
    void func3() {
        cout << "Inside function 3" << endl;
    }
};

int main() {
    
    A object1;
    object1.func1();

    B object2;
    object2.func2();
    object2.func1();

    C object3;
    object3.func1();
    //object3.func2(); //ERROR since class C is not inheriting from class B so, func2() cannot be called by the compiler.
    object3.func3();
}

 */




//why? we are doing different type of inheritance
//HW : go to the documentation of code studio and read the reason
//https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382233


/* 

//Hybrid Inheritance
//combination of more than one type of inheritance 
//For e.g., class B and class C inheriting from class A. At the same time class C is also inheriting from the class D (59:00)
//Above example is the combn. of single and hierarchical type of inheritance.

//HW :- Implementation of Hybrid by self;

// Parent class1 
class Vehicle { 
    public: Vehicle() { 
        cout << "This is a Vehicle" << endl; 
    } 
}; 

//Parent class2 
class Fare { 
    public: Fare() 
    { 
        cout << "Fare of Vehicle\n"; 
    } 
}; 

//Child class1 
class Car: public Vehicle { }; 

//Child class2 
class Bus: public Vehicle, public Fare { }; 

// main function 
int main() { 
    // creating object of sub class will 
    // invoke the constructor of base class 
    Bus obj2; 
    
    return 0; 

} 

 */




/* 
//Inheritance Ambiguity

//If parent class-1 and parent class-2 have the same member ( void abc())
//class-c is inheriting from both classes 1&2 then because of their same member name term inheritance ambiguity arises.
//to avoid inheritance ambiguity, one should use the scope resolution opr(::)


class A {
    public:
    void func() {
        cout << " I am func from class A" << endl;
    }
};

class B {
    public:
    void func() {
        cout << " I am func from class B" << endl;
    }
};

class C : public A, public B {};

int main( ) {

    C object;
    //object.func() //Error: inheritance ambiguity

    object.A :: func();
    object.B :: func();

    return 0;
}

 */


/* 
//POLYMORPHISM
//poly = many, morp = forms

//polymorphism meaning is existing in multiple forms

//2-types of polymorphism :-
// (1). compile time polymorphism
// (2). Run time polymorphism


//(1). compile time polymorphism :- Since this process is executed during compile time, that's why it is known as Compile-Time Polymorphism.
// Also known as static polymorphism
// This type of polymorphism can be achieved through function overloading or operator overloading

#include<iostream>
using namespace std;

class A {

    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }

    //function overloading with an argument
    void sayHello(string name) {
        cout << "Hello using overloaded function" << endl;
    }

    //function overloaded with different argument
    int sayHello(char name) {
        cout << "Hello Love Babbar Bhai" << endl;
        return 1;
    }
};

int main() {
    A obj;
    obj.sayHello();

    return 0;
}

//code studio reference link : https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382250

 */


/* 
//Operator overloading

class B {
    public:
    int a ;
    int b ;

    public:
    int add () {
        return a+b;
    }

    //operator is being overloaded => syntax => [return-type    operator+   (i/p argument)]
    void operator+ (B &obj) {
        int value1 = this -> a;
        int value2 = obj.a;
        cout << "Output => " << value2 - value1 << endl;

    }

    void operator() () {
        cout << "Main Bracket hu => value of a : " << this -> a << endl;
    }
};

int main() {

    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();

    return 0;
}

 */



/* 
//run-time polymorphism (dynamic polymorphism)
//inheritance is important since it depends on it
//method overriding :- when you write your own statement in the function and then inheriting it. Hence, it is known as function overriding


class Animal { 
    public:
    void speak() {
        cout << "Speaking" << endl;
    }
};

class Dog : public Animal {
    public:

    void speak() {
        cout << "Barking" << endl;
    }

};

int main() {
    Dog obj;
    obj.speak();

    //incase there is no speak function in the class Dog then it get called from the Animal class.
}

 */



//Abstraction :- "Implementation Hiding"



//code studio : https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382250

//difference b/w encapsulation and abstraction on stackoverflow : https://stackoverflow.com/questions/742341/difference-between-abstraction-and-encapsulation




// Encapsulation is the packing of "data" and "functions operating on that data" into a single component and restricting the access to some of the object's components.
// Encapsulation means that the internal representation of an object is generally hidden from view outside of the object's definition.

// Abstraction is a mechanism which represent the essential features without including implementation details.

// Encapsulation:-- Information hiding.
// Abstraction:-- Implementation hiding.



//love babbar oops cheatsheet : https://whimsical.com/object-oriented-programming-cheatsheet-by-love-babbar-YbSgLatbWQ4R5paV7EgqFw
