#include<iostream>
using namespace std;


int main () {

   int a;
   cout << "Enter the value of a: " << endl;
   cin>>a; 
   
   // //if a is positive
   //  if(a>0){
   //    cout << "A is a Positive number " << endl;
   //  }
   //  else{
   //    cout << "A is a negative number " << endl;
   // }


   // int b;
   // cout << "Enter the value of b: " << endl;
   // cin>>b;
   // if (a>b){
   //    cout << "a is greater than b" << endl;
   // }else{
   //    cout << "b is greater than a" << endl;
   // }



   // if(a>0){
   //    cout << "a is positive" << endl;
   // }else{
   //    if(a<0){
   //       cout << "a is negative" << endl;
   //    }else{
   //       cout << "a is zero" << endl;
   //    }
   // }


   //OR
   if (a>0)
   {
      cout << "a is a positive no. " << endl;
   }
   else if(a<0){
      cout << "a is a negative no. " << endl;
   }
   else{
      cout << "a is zero " << endl;
   }


   return 0;
}