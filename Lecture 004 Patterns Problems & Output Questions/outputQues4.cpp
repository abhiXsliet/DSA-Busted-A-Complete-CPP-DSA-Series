#include<iostream>
using namespace std;


//Question 4
int main(){

    char ch;
    cout << "Please give the input" << endl;
    cin>>ch;

    if(ch>='A'&&ch<='Z'){
        cout << "This is a Uppercase " << endl;
    }
    else if(ch>='a'&&ch<='z'){
        cout << "This is a Lowercase " << endl;
    }
    else if(ch>='0'&&ch<='9'){
        cout << "This is a numeric " << endl;
    }


    return 0;
}

