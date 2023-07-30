#include<iostream>
using namespace std;

//Here a copy is created and seperate memory is allocated for the variables
void reachHome(int src, int dest) {
    
    cout << "Source is " << src << " Destination is " << dest << endl;

    //base case - when to stop?
    if(src == dest) {
        cout << "\nFinally Home Reached\n" << endl;
        return ;
    }

    //processing - ek step aage badh jao
    src++;

    //recursive call
    reachHome(src, dest);

}

int main() {

    int dest = 10;
    int src  = 1;

    reachHome(src, dest);

    return 0;
}
