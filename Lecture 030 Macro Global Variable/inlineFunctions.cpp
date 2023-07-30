#include<iostream>
using namespace std;



//Inline Functions: are used to reduce the function calls overhead
//Advantage: >no memory usage
//           >no function call
//           >no performance hit like it was hitting during fn. call
//           >inline works on single line, may or may not work on 2/3 line, (will not work on >3 line)

inline int getMax(int a , int b) {
    
    return (a>b) ? a : b;

}

int main(){

    int a = 1; 
    int b = 2;
    int ans = 0;

    // getMax will be replaced before executing code by (a>b)?a:b; since it is an inline 
    // inline benefits: no extra memory allocation, no fn. call, no performance hit because no fn. get called
    ans = getMax(a,b); 
    cout << ans << endl;

    a = a + 3;
    b = b + 1;

    ans = getMax(a, b);
    cout << ans << endl;

    return 0;
}

