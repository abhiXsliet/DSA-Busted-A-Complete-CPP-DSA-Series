#include<iostream>
using namespace std;

//reverse a string
void reverseString(string& str, int i, int j) {
    
    cout << "call received for " << str << endl;
    
    //base case
    if(i>j) {
        return ;
    }

    //processing - one step
    swap(str[i], str[j]);
    i++;
    j--;

    //Recursive call
    reverseString(str, i, j);

}

int main() {

    string name = " ";
    cout << "\nEnter the word in the string => ";
    cin>>name;
    cout << endl;

    reverseString(name, 0, name.length()-1);

    cout << "Characters in reversed String will be => " << name << endl << endl;

    return 0;
}
