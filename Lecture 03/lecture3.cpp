#include<iostream>
using namespace std;

/*

int main()
{
   int a;
   cin>>a;
   cout << "the value of n is: " << a << endl;

   //if a is positive
    if(a>0){
      cout << "A is a Positive number " << endl;

    }
    else{
      cout << "A is a negative number " << endl;

   }
}
 

int main(){
   int a, b;
   cout << "Enter the value of a: " << endl;
   cin>>a;
   cout << "Enter the value of b: " << endl;
   cin>>b;

   if (a>b){
      cout << "a is greater than b" << endl;

   }else{
      cout << "b is greater than a" << endl;

   }

} 


int main(){
   int a;
   cout << "Enter the value of a: " << endl;
   cin>>a; 

   if(a>0){
      cout << "a is positive" << endl;
   }else{
      if(a<0){
         cout << "a is negative" << endl;
      }else{
         cout << "a is zero" << endl;
      }
   }
}

 

int main(){

   int a;
   cout<<"n = ";
   cin>>a;

   if (a>0)
   {
    cout << "a is a positive no. " << endl;
   }
    else if(a<0){
    cout << "a is a negative no. " << endl;
   }else
    {
    cout << "a is zero " << endl;
    }
}


  
//print number from 1 to n
int main(){
   int n;
   cout << "n = ";
   cin>>n;
   
   
   int i=1;
   
   while(i<=n){
      cout << i << " " ;
      i = i+1;
   }
}   


// Sum of number from 1 to n

int main(){
   int n;
   cout << "n = ";
   cin>>n;

   int i = 1;
   int sum = 0;

   while(i<=n){

      sum = i + sum;
      
      i = i+1;

   }
    cout << "The value of sum is: " << sum << " " << endl;
}
  

//sum of even no.s from 1 to n
int main(){
   int n;
   cout << "n =  ";
   cin>>n;

   int i = 2;
   int sum = 0;

   while (i<=n){

      sum = i + sum;

      i = i + 2;

   }
   cout << "The sum of all even numbers in between the provided number is: " << sum << endl;
}
 

//fahrenheit to celcius conversion.


int main(){

   float f,c;
   cout << "Enter the temperature in fahreheit" << endl;
   cin>>f;

   c = 5*(f-32)/9;
   cout << f << " fahrenheit is equal to " << c << " degree celsius" << endl;

}

//celsius to fahrenheit coversion.

int main(){

   double f, c;
   cout << "Enter the temperature in celsius" << endl;
   cin>>c;

   f = c*9/5 + 32;
   cout << c << " celsis is equal to " << f << " fahrenheit" << endl;


}




//Check prime no using while loop

int main(){
   
   int n;
   cout << "n = ";
   cin>>n;

   int i = 2;

   while(i<n) {

      if(n%i==0) {

         cout << "Not prime for " << i << endl;
      }
      else{
         cout << "Prime for " << i << endl;
      }
      i = i +1;

   }
   

}



//printing even no. with for loop
int main(){
   int n;
   cout<<"n = ";
   cin>>n;

   int i;
   for(i=2; i<=n; i++){
      cout<<i<<endl;
      i++;
   }
}



//printing prime no. with for loop


 int main(){

   int n;
   cout<< " n = ";
   cin>> n;

   bool isPrime = 1;
   for (int i = 2; i < n; i++)
   {
      if(n%i == 0)
      {
         isPrime = 0;
         break;

      }
   }

   if (isPrime == 0)
   {
      cout<< n <<" is not a prime no."<<endl;

   }
   else{
      cout<< n <<" is a prime no."<<endl;
   }
 }
 
*/