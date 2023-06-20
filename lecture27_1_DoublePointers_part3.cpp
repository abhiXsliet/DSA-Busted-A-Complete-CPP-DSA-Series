#include<iostream>
using namespace std;

void update(int **p2){
    //p2 = p2 + 1;
    //kuch change hoga?? --> No

    //*p2 = *p2 + 1;
    //kuch change hoga?? --> Yes (p)

    **p2 = **p2 + 1;
    //kuch change hoga?? --> Yes (i)
}

int main(){

    int i = 5;
    int* p = &i;
    int** p2 = &p;
/* 
    cout << endl;
    cout << "Printing p (&i) : " << p << endl;        //p me i ka address hai. [p=&i]
    cout << "Address of p (&p) : " << &p << endl;     //p ka address = &p;

    cout << endl;
    cout << "Printing *p : " << *p << endl;     //*p = Printing at the address stored in p which is Printing of i;
    cout << "Printing i  : " << i << endl;
    cout << "Printing **p2 : " << **p2 << endl;    //**p2 = Printing at add. of p(i.e., &p and &i) [**p2 = &p --> &i]

    cout << endl;
    cout << "Printing &i : " << &i << endl;
    cout << "Printing p : " << p << endl;
    cout << "Printing *p2 (&p) : " << *p2 << endl;  //*p2 = address of p while *p = Printing of i

    cout << endl;
    cout << "Printing &p : " << &p << endl;
    cout << "Printing p2 :  "<< p2 << endl;     //p2 is holding the add. of p (i.e., p2 = &p)
    cout << endl ;

 */



    //POINTER & FUNCTIONS:-
    cout << "BEFORE :- " << endl;
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl << endl;
    update(p2);
    cout << "After :- " << endl;
    cout << i << endl;
    cout << p << endl;
    cout << p2 << endl;




    return 0;
}