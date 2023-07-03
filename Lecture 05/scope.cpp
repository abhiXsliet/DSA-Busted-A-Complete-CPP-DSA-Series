#include<iostream>
using namespace std;

//variable and scoping
int main(){
    
    int a = 3;
    cout << a << endl;

    if (true){
        int b = 5;
        cout << b << endl;
    }

    int b = 1;
    cout << b << endl;

    int i=8;
    for( ; i<8; i++) {
        cout << "HI" << endl;
    }

    // variable (b) has different scope a/c to their respective (if) condition
    if(1) {
        int b;
        if(1) {
            int b;
            if(1) {
                int b;
            }
        } 
    }
}

