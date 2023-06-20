/* 


#include<iostream>
#include "lecture42_1_Oops_part1.cpp"
using namespace std;

int main() {

    //creation of object
    Hero ramesh;
    
    ramesh.health = 5;
    ramesh.level = 'A';

    cout << "Health is : " << ramesh.health << endl;
    cout << "Level is : " << ramesh.level << endl;

}


 */


/* 

#include<iostream>
using namespace std;

class Hero {

    private:
    int health2;
    char level2 = 'B';

    public:
    int health;
    char level;

    //direct printing in class is wrong
    //cout << "We can access level2 here => " << level2 << endl;
    void print() {
        cout << "We can access level2 here => " << level2 << endl;
    }


    //getter :- are used to simply fetch
    char getLevel() {
        return level2;
    }

    int getHealth2() {
        return health2;
    }

    //setter :- are used to change the values by the user after fetching
    //it also used as to implement some specific condition or password, so that if the codn. occurs then only one can change the value of setter
    void setHealth2(int h) {
        health2 = h;
    }

    void setLevel(char ch) {
        level2 = ch;
    }
    
};

class Hero2 {


};

int main() {

    //object instanciated
    //statically allocation
    Hero ramesh;


    //dynamically allocation
    Hero *b = new Hero;

    
    //setting object values(properties)
    ramesh.health = 10;
    ramesh.level = 'Z';

    cout << "\nHealth of Hero is : " << ramesh.health << endl;
    cout << "level of Hero is : " << ramesh.level << endl;

    //cout << "level2 of Hero is : " << ramesh.level2 << endl;
    //we can't access the level2 because it lies into the private section

    cout << endl << endl;

    //** If one want to access the private memebers of the class then can be done by using getter and setter;
    cout << "ramesh level2 is :=> " << ramesh.getLevel() << endl;
    cout << "ramesh health2 is :=> " << ramesh.getHealth2() << endl << endl ;
    
    ramesh.setHealth2(100);
    cout << "ramesh health after setter :=> " << ramesh.getHealth2() << endl << endl;

    cout << "size of health2 is :=> " << sizeof(ramesh.getHealth2()) << endl << endl;

    cout << "size of object ramesh (Hero class) => " << sizeof(ramesh) << endl  << endl;
    Hero2 unknown;
    cout << "size of unknown is (empty class Hero2) :=> " << sizeof(unknown) << endl << endl << endl;
    
    /////////////////////////////////////////////////////////////
    /////   HW := read about padding and greedy alignment   /////
    /////////////////////////////////////////////////////////////
    
    //processor doesn't read 1-byte at a time, it read 1-word at a time which is equal to 4-bytes in 32-bit processor and 8-bytes in 64-bit processor.
    //To avoid the un-necessary wastage of cpu cycle concept of padding was introduced. The padding is done automatically by the compiler.
    //If we change the order of variables then their value of o/p also changes because padding works differently
    //Link : https://www.javatpoint.com/structure-padding-in-c
    //disadvantage of padding is that wastage of memory occurs in padding.

    //Alignment refers to the arrangement of the data in the memory and specifically deals with the issue of accessing data as proper units of informatioin from the main memory.



    return 0;
}


 */


/* 
#include<iostream>
using namespace std;

class Hero {
    
    //properties
    private:
    int health;

    public:
    char level;

    //DEFAULT constructor creation , after manual creation of default constructor previous default constructor will be eliminated by the compiler
    Hero() {
        cout << "DEFAULT constructor called" << endl;
    }

    //**when you created any type of your own constructor either parameterized or default then previous default constructor gets terminated

    //Parameterized constructor
    //'this' keyword came into play when we use same i/p parameter and the data member
    //this is a pointer who is representing the data member int health.
    Hero(int health){
        cout << "this => " << this << endl;
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    void print() {
        cout << level << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }
    
};


int main() {

    //static allocation
    Hero a;

    a.setHealth(50);
    a.setLevel('B');

    cout << endl;

    //accessing data member by using dot(.) operator
    cout << "Level is :  " << a.level << endl;
    cout << "health is : " << a.getHealth() << endl;
    cout << endl << endl;


    //dynamically
    Hero *b = new Hero;

    (*b).setHealth(90);
    b->setLevel('X'); //or (*b).setLevel('X');

    //accessing data member in dynamically by using either dot-operator(.) and de-reference operator(*) or ->
    cout << "Level is :  " << (*b).level << endl;
    cout << "health is : " << (*b).getHealth() << endl;

    cout << "Level is (->) :  " << b->level << endl;
    cout << "health is(->) : " << b->getHealth() << endl;



    return 0;
}

 */


/* 

//** whenever we create an object then their constructor is called by the compiler
//Constructor ?
//properties of constructor : 1. envoke during object creation 2. no return type 3.right below we just saw has no i/p parameter also

int main() {

    //object created statically
    cout << "Hi" << endl;
    Hero ramesh;
    //after objected being created a DEFAULT CONSTRUCTOR ENVOKED (i.e., ramesh.Hero()) by the compiler bts;
    cout << "Hello" << endl;

    cout << endl << endl;

    //objected created dynamically
    cout << "before dynamic object  " << endl;
    Hero *s = new Hero; //new Hero || new Hero() no difference at all
    //same constructor will be called in case of dynamically created object as it was called during statically created object
    cout << "after dynamic object " << endl;
    s -> print(); //valid only for dynamically created object

    cout << endl << endl;

    Hero kalia(10);
    cout << "Address of kalia => " << &kalia << endl;

    cout << endl << endl;

    Hero temp(22, 'F');
    cout << "health of temp is :=> " << temp.getHealth() << endl;
    cout << "level of temp :=> " << temp.getLevel() << endl;
    cout << "------------Another Way----------" << endl;
    temp.print();

    cout << endl << endl;
    return 0;

}

 */


/* 
#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    private:
    int health;

    public:     
    char level;

    Hero() {
        cout << endl;
        cout << "Simple constructor called " << endl;
    }

    //parameterized constructor
    Hero(int health) {
        this -> health = health;
    }

    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }

    //copy constructor //** when you created your own copy constructor then previous default copy constructor gets terminated
    Hero(Hero& temp) { //& why? watch at (55:00)
        
        cout << "copy constructor called" << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "health : " << this -> health << endl;
        cout <<  "level : " << this -> level << endl;
    }


    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }  

    void setLevel(char ch) {
        level = ch;
    }  

};

int main() {

    Hero s(70, 'C');
    s.print();

    cout <<  endl;

    //copy constructor
    Hero R(s);
    R.print(); 

}

 
 */




/* 
#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;


    Hero() {
        cout << endl;
        cout << "Simple constructor called " << endl;
        name = new char[100]; //allocating memory of array on heap dynamically
    }

    //parameterized constructor
    Hero(int health) {
        this -> health = health;
    }

    //copy constructor
    Hero(Hero& temp) {
        
        //deep copy
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this -> name = ch;

        cout << "\nCopy constructor called " << endl;
        this -> health = temp.health;
        this -> level = temp.level;
    }

    Hero(int health, char level){
        this -> health = health;
        this -> level = level;
    }

    void print(){
        cout << endl;
        cout << "[ name : " << this -> name << ", " ;
        cout << "health : " << this -> health << ", ";
        cout <<  "level : " << this -> level << " ]";
        cout << endl ;
    }


    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }  

    void setLevel(char ch) {
        level = ch;
    }  

    void setName(char name[]) {
        strcpy(this ->name, name);
    }

};


int main() {
    
    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[9] = "Babbar";
    hero1.setName(name);

    hero1.print();

    //use default copy constructor

    Hero hero2(hero1);  //Hero hero2 = hero1;
    hero2.print();

    //shallow copy
    hero1.name[0] = 'G';
    hero1.print();

    //deep copy
    hero2.print();


    //copy Assignment Operator
    hero1 = hero2;
    
    hero1.print();
    hero2.print();

    cout << endl << endl;


    return 0;
    
}

 */
//documentation code studio : https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118817/offering/1382186



/* 
//DESTRUCTOR :- is used to de-allocation of memory
//properties : 
//1. name is same as class
//2. no return type
//3. no input parameter

#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;

    ~Hero() {
        cout << "Destructor bhai called " << endl;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }  

    void setLevel(char ch) {
        level = ch;
    }  

    void setName(char name[]) {
        strcpy(this ->name, name);
    }

};

int main() {

    //static
    Hero a; 
    //In static, destructor gets automatically called by the compiler
    //destructor is automatically created when a class is created but one can also manually create a destructor. Hence, after manual creation of any type of destructor previous default destructor gets terminated.

    //dynamic
    Hero *b = new Hero();
    //for dynamic, destructor have to manually called by the user
    delete b;

    return 0;


}

 */


//HW : what is 'const' keyword? How it used in object creation? How const keyword is used in data member? How one can create const type function?
// Initialisation list concept?





/* 
//static keyword

#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;
    static int timeToComplete;


    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }  

    void setLevel(char ch) {
        level = ch;
    }  

    void setName(char name[]) {
        strcpy(this ->name, name);
    }

};

//initialise
//data type :: field Name = value (:: = scope resolution operator)

int Hero :: timeToComplete = 5;

int main() {

    cout << Hero::timeToComplete << endl;

    Hero a;

    // //not recommended at all since this static member not belongs to objects but class
    // cout << a.timeToComplete << endl;

    // Hero b;
    // b.timeToComplete = 10;
    // cout << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;


}

 */





//static function (properties:)
//1. not need to create object. Since you can directly call this fn. by their class name 
//2. Since here is no current object so, this keyword is not here because this keyword is a pointer to current object
//3. static fn. can only access static member


//static keyword

#include<bits/stdc++.h>
using namespace std;

class Hero {
    
    int health;

    public:     
    char* name; //char name[100] :-> bad practice so that one should do it dynamically
    char level;
    static int timeToComplete;

    static int random() {
        // wrong => cout << health << endl;
        // wrong => cout << level << endl;
        // wrong => cout << name << endl;

        return timeToComplete;
    }

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }  

    void setLevel(char ch) {
        level = ch;
    }  

    void setName(char name[]) {
        strcpy(this ->name, name);
    }

};

int Hero :: timeToComplete = 5;

int main() {

    cout << Hero :: random() << endl;

}


//prefer reading documentation of code studio for theory 