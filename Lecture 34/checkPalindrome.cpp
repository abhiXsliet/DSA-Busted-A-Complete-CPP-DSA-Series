#include<iostream>
using namespace std;
 
//check palindrome
bool checkPalindrome(string str, int i, int j) {

    //base case
    if(i>j){
        return true;
    }

    //processing 
    if(str[i] != str[j]){
        return false;
    }else
    {
        //recursive call
        return checkPalindrome(str, i+1, j-1);
    }

}

int main() {
    cout << "\nEnter the word in the string => " ;
    string name = " ";
    cin>>name;

    cout << endl;

    bool isPalindrome = checkPalindrome(name, 0, name.length()-1 );

    if(isPalindrome){
        cout << "Yes! It's a palindrome" << endl << endl;

    }else{
        cout << "Nope! Not a palindrome" << endl << endl ;
    }

    return 0;
}

//In HW : Remove the second pointer j and try to solve question 
//HINT : use n-i-1;
