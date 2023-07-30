#include<iostream>
using namespace std;

// AP = (3*n+7)
int ap(int n){
    int ap = (3*n+7);
    return ap;
}

int main(){
    int n;
    cout << "\nGive your input: " ;
    cin>>n;

    //Way-1
    int AP = (3*n+7);
    cout << "\nYour output will be: " << AP << endl << endl;

    //Way-2
    cout << "\noutput will be: \n" ;
    for(int i=1; i<=n-1; i++){
        int ans = (3*i+7); 
        cout << ans << ", ";
    }cout << (3*n+7) ;

    //Way-3
    int ans = ap(n);
    cout << "\nOutput will be: " << ans << endl << endl;
}
