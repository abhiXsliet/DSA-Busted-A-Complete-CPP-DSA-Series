#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){

    //How will you exit? if you put switch case inside an infinte loop and you can't use switch statement.
    //EXAMPLE
    //  while(1)
    // {
    //     cout<<"HOW YOU DOIN MAN??"<<endl;
    //     int num = 1;
    //     switch (num)
    //     {
    //     case 1: cout<<"I'M FINE"<<endl;
    //         break;
    //     }
    //    exit(0);
    // }


    //Solve the no. of notes required of different value of currencies
    int amount;
    cout << "Amount = ";
    cin>>amount;
    switch (1)
    {
        case 1 : cout << "No. of 100 rupees notes: "<< amount/100 << endl;
                amount = amount%100;
        case 2 : cout << "No. of 50 rupees notes: " << amount/50 <<endl;
                amount = amount%50;
        case 3 : cout << "No. of 20 rupees notes: " << amount/20 <<endl;
                amount = amount%20;
        case 4 : cout << "No. of 10 rupees notes: " << amount/10 <<endl;
                amount = amount%10;
    }
}

