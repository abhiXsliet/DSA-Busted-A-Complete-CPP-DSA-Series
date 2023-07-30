#include<iostream>
using namespace std;

void pattern1(int n) {
    int i = 1;

    while(i<=n){

        int j = 1;

        while(j<=n){
            cout << j;
            j = j + 1;
        }
        cout << endl;

        i = i + 1;

    }
}

void pattern2(int n) {
    int i = 1;

    while(i<=n){

        int j = 1;

        while(j<=n){
            cout << n - j + 1;
            j = j + 1;
        }
        cout << endl;

        i = i + 1;

    }

}

void pattern3(int n) {
    int i = 1;
    int count = 1;

    while(i<=n){

        int j = 1;
        while(j<=n){

            cout << count <<" ";
            count = count + 1;

            j = j + 1;
        }
        cout << endl;

        i = i + 1;
    }
}

void pattern4(int n) {
    int row = 1;
    while(row<=n){

        int col = 1;
        while(col<=row){
            cout << "*";
            col = col + 1;

        }
        cout << endl;
        row = row + 1; 
    }
}

void pattern5(int n) {
    int row = 1;
    while(row<=n){

        int col = 1;
        while(col<=row){
            cout<<row;
            col = col + 1;

        }
        cout << endl;
        row = row +1;

    }
}

void pattern6(int n) {
    int row = 1;
    int count = 1;

    while(row<=n){

        int col = 1;
        while (col<=row)
        {
            cout << count;
            count = count + 1;
            col = col + 1;
        }
        cout << endl;

        row = row + 1;
        
    }
}

void pattern7(int n) {
    
    int row = 1;
    while(row<=n){

        int col = 1;
        int value = row;

        while(col<=row)
        {
            cout<<value;
            value = value + 1;
            col = col + 1;

        }
        cout << endl;
        row = row + 1;
    }
}

//other way of doing above question
void pattern7_Another(int n) {
    int row = 1;
    while (row<=n){

        int col = 1;

        while(col<=row)
        {
            cout<<(row+col-1)<< " ";
            col = col + 1;
            
        }
        cout << endl;

        row = row + 1;

    }
}

void pattern8(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;
        while(j<=i){
            cout<<(i-j+1)<<" ";
            j = j + 1;
        }
        cout << "\n";
        i = i + 1;
    }
}

//other way for solving above question
void pattern9(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;
        int value = i;
        while(j<=i){
            cout<<value<< " ";
            value = value - 1;
            j = j + 1;

        }
        cout << endl;
        i = i + 1;
    }
}

void pattern10(int n) {
    
    int i = 1;
    while(i<=n){

        int j = 1;
        while(j<=n){

            char ch = 'A' + i - 1;
            cout<<ch;
            j = j + 1;

        }
        cout << endl;
        i = i + 1;
    }
}

void pattern11(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;

        while(j<=n){

            char ch = 'A' + j - 1;

            cout<<ch;
            j = j + 1;

        }
        cout << endl;

        i = i + 1;

    }
}

void pattern12(int n) {
    int i = 1;
    char start = 'A';
    while(i<=n){

        int j = 1;
        while(j<=n){
            
            cout<<start;

            start = start + 1;
            j = j + 1;

        }
        cout << endl;
        i = i + 1;
    }
}

void pattern13(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;

        char ch = 'A' + i + j - 2; //i+j-1 = 'A' ye laane ke lye 'A' - 1 dono traf add krke 'A'+i+j-2 = 'A' aaya hai.
        
        while(j<=n){

            cout<<ch;

            ch = ch + 1;
            j = j + 1;

        }
        cout << endl;
        i = i + 1;
    }
}

void pattern14(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;
       
        while(j<=i){
            
            char ch = 'A' + i - 1;

            cout<<ch;
            
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}

void pattern15(int n) {
    int i = 1;
    char ch = 'A';

    while(i<=n){

        int j = 1;
        
        while(j<=i){
            
            cout<<ch;
        
            ch = ch + 1;
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}

void pattern16(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;
       
        while(j<=i){
            
            char ch = 'A' + i + j - 2;

            cout<<ch;
            
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}

void pattern17(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;

        char ch = 'A' + n - i;

        while(j<=i){
            
            cout<<ch;
            ch = ch + 1;
            
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}

//one of the above question as  A B C 
//                              B C D 
//                              C D E 
// this question in easy way
void pattern18(int n) {
    int i = 1;
    while(i<=n){

        int j = 1;
        char ch = 'A' + i - 1;

        while(j<=n){

            cout<<ch;
            
            ch = ch + 1;
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}

void pattern19(int n) {
    int i = 1;
    while(i<=n){

        //running first while loop for spaces
        int space  = n - i;
        while(space){

            cout << " ";
            space = space - 1;

        }

        //running second while loop for *
        int j = 1;
        while(j<=i){

            cout<<"*";
            
            j = j + 1;

        }
        cout << endl;
        i = i + 1;
    }
}

void pattern20(int n) {
    int i = 1;
    while(i<=n){
      
        //running second while loop for * 
        int j = 1;
        while(j<=n-i+1){

            cout<<"*";
            
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}

void pattern21(int n) {
    int i = 1;
    while(i<=n){

        //running first while loop for spaces
        int space  = i - 1;
        while(space){

            cout << " ";
            space = space - 1;

        }

        //running second while loop for *
        int j = 1;
        while(j<=n-i+1){

            cout<<"*";
            
            j = j + 1;

        }
        cout << endl;
        i = i + 1;
    }
}

void pattern22(int n){
    int i = 1;
    while(i<=n){

        //running first while loop for spaces
        int space  = i - 1;
        while(space){

            cout << " ";
            space = space - 1;

        }

        //running second while loop for *
        int j = 1;
        while(j<=n-i+1){

            cout<<i;
            
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}

void pattern23(int n) {
    int i = 1;
    while(i<=n){

        //running first while loop for spaces
        int space  = n - i;
        while(space){

            cout << " ";
            space = space - 1;

        }

        //running second while loop for 
        int j = 1;
        while(j<=i){

            cout<<i;
            
            j = j + 1;

        }
        cout << endl;

        i = i + 1;
    }
}


void pattern24(int n) {
    int i = 1;
    while(i<=n){

        //coding for spaces first
        int space = i - 1;
        while(space){

            cout<<" ";
            space = space - 1;

        }

        //coding for numbers now in second while loop
        int j = 1;
        int k = i+j-1;
        while(j<=n-i+1){

            cout<<k;
            k = k + 1;
            j = j + 1;

        }
        cout<<endl;
        i = i + 1;
    }
}

void pattern25(int n) {
    int i = 1;
    int count = 1;
    while(i<=n){

        int space = n - i;
        while(space){

            cout<<" ";
            space = space - 1;
        }

        int j = 1;
        while(j<=i){

            cout<<count;
            count = count + 1;
            j = j + 1;

        }
        cout<<endl;
        i = i + 1;
    }
}

void pattern26(int n) {
    int i = 1;
    while(i<=n){

        //first triangle space wala print krte hai
        int space = n - i;
        while(space){

            cout<<" ";
            space = space - 1;
        }

        //second triangle print krte hai
        int j = 1;
        int value = 1;
        while(j<=i){

            cout<<value; //Also, we can directly print j, if we don't want to specifiy value
            value = value + 1;

            j = j + 1;

        }

        // third triangle print krlete hai aab
        int start = i - 1;
        while (start)
        {
            cout<<start;
            start = start - 1;
        }
        
        cout << endl;
        i = i + 1;
    }
}

void pattern27(int n) {
    int i = 1;
    while(i<=n){

        //first triangle printing for the numbers only
        int j = 1;
        while(j<=n-i+1){

            cout<<j;  //also you can do this by supposing value = 1; same as above
            j = j + 1;
            
        }

        //second triangle printing for the stars only
        int start = i - 1;
        while(start){

            cout<<"**";
            start = start - 1;
        }

        //third triangle printing for the numbers only
        int k = 1;
        while(k<=n-i+1){
            cout<<k;
            k++;
        }
        cout << endl;
        i = i + 1;
    }
}

int main(){

    int n;
    cout << "\nPlease input a number => ";
    cin>>n;

    // pattern1(n);

    // pattern2(n);

    // pattern3(n);

    // pattern4(n);

    // pattern5(n);

    // pattern6(n);

    // pattern7(n);
    // pattern7_Another(n);

    // pattern8(n);

    // pattern9(n);

    // pattern10(n);

    // pattern11(n);

    // pattern12(n);

    // pattern13(n);

    // pattern14(n);

    // pattern15(n);

    // pattern16(n);

    // pattern17(n);

    // pattern18(n);

    // pattern19(n);

    // pattern20(n);

    // pattern21(n);

    // pattern22(n);

    // pattern23(n);

    // pattern24(n);

    // pattern25(n);

    // pattern26(n);

    // pattern27(n);


    return 0;
}


