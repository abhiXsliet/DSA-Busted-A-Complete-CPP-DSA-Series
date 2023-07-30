#include<iostream>
using namespace std;


//Fibonacci series 
//Recursive relation : f(n) = f(n-1) + f(n-2);

int fibSeries(int n) {

    //base case
    if((n == 0) ||(n == 1)) {
        return  n;
    }

    //R.R
    return fibSeries(n-1) + fibSeries(n-2);

}


int main() {

    int n;
    cout << "\nEnter n = ";
    cin>>n;

    int ans = fibSeries(n);
    cout << n << "th fibonacci series will be => " << ans << endl << endl;

    return 0;
}
