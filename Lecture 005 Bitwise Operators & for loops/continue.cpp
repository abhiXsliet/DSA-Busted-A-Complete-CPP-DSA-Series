#include<iostream>
using namespace std;


//continue is used to skip the iternation
int main ()
{
    for (int i = 0; i<5; i++)
    {
        cout << " HI " << endl;
        cout << " Hey " << endl;
        continue;
        
        //this iteration is skipped here
        cout << "Reply toh karde" << endl;
    }

    
    // //here iteration is not being skipped
    // for (int i = 0; i<5; i++)
    // {
    //     cout << " HI " << endl;
    //     cout << " Hey " << endl;
    //     
    //     cout << "Reply toh karde" << endl;
    // }
    

    for(int i = 0; i<=15; i += 2){
        cout << i << " ";
        if( i&1 ){
            continue;
        }
        i++;
    }

    for (int i=0; i<=5; i++){
        for(int j=1; j<=5; j++){
            if (i+j == 10){
                break;
            }
            cout<< i << " " << j << endl;
        }
    }
}