#include<iostream>
using namespace std;

/*
int main(){

    int a = 4;
    int b = 6;

    cout<< " a&b " << (a&b) << endl;
    cout<< " a|b " << (a|b) << endl;
    cout<< " ~a " << (~a) << endl;
    cout<< " a^b " << (a^b) << endl; 

    cout << (17>>1) << endl;
    cout << (17>>2) << endl;
    cout << (19<<1) << endl;
    cout << (21<<2) << endl;

    int i = 7;

    cout << (++i) << endl;
    cout << (i++) << endl;
    cout << (i--) << endl;
    cout << (--i) << endl;

    //practice this more for some easy interview question



}




int main(){

     int a, b = 1;
     a = 10;
     if (++a)
        cout << b;
     else
        cout << ++b;
}




int main(){

    int a = 1;
    int b = 2;

    if ( a-- > 0 && ++b > 2){
        cout<< "Stage1 - Inside If ";

    }else{
        cout << "Stage2 - Inside else " ;
    
    }
    cout << a << " " << b << endl;
}




int main(){
    int number = 3;
    cout << (25 * (++number));
}




int main(){

    int a = 1;
    int b = a++;
    int c = ++a;
    cout << b;
    cout << c;
}





//for loop

int main(){

    int n;
    cout<<"Enter the value of n"<<endl;
    cin>>n;

    cout<<"printing count from 1 to n "<< endl;
    int i = 1;

    for(i=1; i<=n; i++){
        cout<<i<<endl;

    }
}



//other way of doing for loop

int main(){

    int n;
    cout<<"enter the value of n "<<endl;
    cin>>n;

    cout<<"printing the value from 1 to n"<<endl;

    int i = 1;
    for(;;){
        if(i<=n){
            cout<< i << endl;
        }
        else{
            break;
        }
         i++;

    }

   

}



//we can do multiple initialisation/condition/increment,decrement at the same time

int main(){

    int n;
    cout << "enter the value of n"<< endl;
    cin>>n;

    cout<<"printing the count from 1 to n" << endl;

    for (int a = 0, b = 1, c = 2; a>=0 && b>=1 && c>=2; a--, b--, c--){
        cout<< a << " " << b << " " << c << endl;

    }
}



//find the sum of n numbers using the for loop

int main(){

    int n;
    cout << "enter the value of n"<<endl;
    cin>>n;

    cout << "printing the sum from 1 to n is: "<<endl;
    
    int sum = 0;

    for (int i=1; i<=n ; i++){
        
        //sum = sum + i;
        sum += i;

    }
    cout << sum << endl;

    
}



//fibonacci series using for loop
//fibonacci series means any number is the sum of pervious two numbers

int main(){

    int n;
    cout << "enter a numeric value of n" << endl;
    cin>>n;

    int a = 0;
    int b = 1;
    cout << a << " " << b << " " ;

    for (int i = 1; i<=n ; i++){

        int nextNumber = a+b;
        cout << nextNumber << " ";

        a = b;
        b = nextNumber;

    }



}





//check wheather the number is prime or not using for loop

 int main(){

    int n;
    cout<< "enter the value of n" << endl;
    cin>>n;

    bool isPrime = 1;

    for(int i = 2; i<n; i++){

        if (n%i == 0){

            isPrime = 0;
            break;

        }
    }

    if (isPrime == 0) {

        cout << "Not a prime number" << endl;

    }
    else
    {
        cout << "is a Prime Number" << endl;
    }


 }
 



//continue is used ot skip the iternation


int main ()
{
    for (int i = 0; i<5; i++)
    {
        cout << " HI " << endl;
        cout << " Hey " << endl;
        continue;
        
        //this iteration is skipped here
        cout << "Reply toh karde" << endl;
    }
}

//here iteration is not being skipped

int main ()
{
    for (int i = 0; i<5; i++)
    {
        cout << " HI " << endl;
        cout << " Hey " << endl;
       // continue;

        cout << "Reply toh karde" << endl;
    }
}

 
 

int main(){

    for(int i = 0; i<=5; i++){
        cout<< i << " ";
        i++;
    }
}


int main(){

    for (int i = 0; i<=5; i--){

        cout << i << " ";
        i++;
    }
}




int main(){
    
    for(int i = 0; i<=15; i += 2){
        cout << i << " ";

        if( i&1 ){
            continue;
        }

        i++;
    }
}



int main(){

    for (int i = 0; i<5; i++){
        for (int j=1; j<=5 ; j++){
            cout<< i << " " << j << endl;

        }
    }
}



int main(){

    for (int i=0; i<5; i++){

        for(int j=1; j<=5; j++){
            if (i+j == 10){
                break;
            }
            cout<< i << " " << j << endl;
        }
}

}



//variable and scoping
//L5 timestamp 55:00 (Love)

int main(){
    
    int a = 3;
    cout << a << endl;

    if (true){
        int b = 5;
        cout << b << endl;
    }
    int b = 1;
    cout << b << endl;

}

*/


//2-LEET CODE QUESTION SOLVED

