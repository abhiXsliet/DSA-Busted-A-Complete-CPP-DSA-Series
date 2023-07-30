#include<iostream>
using namespace std;

//function signature
int power(){
    int a, b ;
    cout << "Enter two numbers as(space separated) => ";
    cin >> a >> b;

    int ans = 1;
    for (int i = 1; i<=b; i++){
        ans = ans * a;  
    }
    return ans;
}

int power(int num1, int num2){
    
    cout << "Enter two numbers (space separated): ";
    cin >> num1 >> num2;
    int ans = 1;
    for (int i = 1; i<=num2; i++){
        ans = ans * num1;  
    }
    return ans;
}

int main(){


    //this code is written in bulky 
    int a, b;
    cout<<"Enter the value of a b : ";
    cin>> a >> b;
    int ansR = 1;
    for (int i = 1; i<=b; i++){
        ansR = ansR * a;
    }
    cout << "Answer is: " << ansR << endl;

    int c, d;
    cout<<"Enter the value of c d : ";
    cin>> c >> d;
    ansR = 1;
    for (int i = 1; i<=d; i++){
        ansR = ansR * c;
    }
    cout << "Answer is: " << ansR << endl;

    int e, f;
    cout<<"Enter the value of e f : ";
    cin>> e >> f;
    ansR = 1;
    for (int i = 1; i<=f; i++){
        ansR = ansR * e;
    }
    cout << "Answer is: " << ansR << endl;


    //BY FUCTION CALL
    //Way-1
    int a1, b1;
    int answer = power(a1,b1);
    cout << "Answer is: " << answer << endl;

    int c1, d1;
    int answer1 = power(c1,d1);
    cout << "Answer is: " << answer1 << endl;

    int e1, f1;
    int answer2 = power(e1,f1);
    cout << "Answer is: " << answer2 << endl;

    //Way-2
    int sol = power();
    cout << "Answer is: " << sol << endl;
    int sol1 = power();
    cout << "Answer is: " << sol1 << endl;
    int sol2 = power();
    cout << "Answer is: " << sol2 << endl;

    return 0;
}

