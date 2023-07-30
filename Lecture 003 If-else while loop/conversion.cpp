#include<iostream>
using namespace std;



int main(){

    // fahrenheit to celcius conversion.
    float f,c;
    cout << "Enter the temperature in fahreheit" << endl;
    cin>>f;
    c = 5*(f-32)/9;
    cout << f << " fahrenheit is equal to " << c << " degree celsius" << endl;


    // // celsius to fahrenheit coversion.
    // double f, c;
    // cout << "Enter the temperature in celsius" << endl;
    // cin>>c;
    // f = c*9/5 + 32;
    // cout << c << " celsis is equal to " << f << " fahrenheit" << endl;

    return 0;
}
