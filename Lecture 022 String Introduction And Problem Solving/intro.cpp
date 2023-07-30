#include<bits/stdc++.h>
using namespace std;

//TO LOWER CASE CONVERSION OF ALPHABETS
char toLowerCase(char ch) {
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

//CHECK PALINDROME USING FOR LOOP
bool checkPalindrome1(char a[], int size) {
    for(int i=0; i<size; i++){
        if(a[i] != a[size-i-1]) {
            return 0;
        }
    }
    return 1;
}

//CHECK PALINDROME USING WHILE LOOP
bool checkPalindrome2(char a[], int size) {
    int s = 0;
    int e = size - 1;
    while( s < e ) {
        //non-case sensitive
        if( toLowerCase(a[s]) != toLowerCase(a[e]) ) {
            return 0;
        }
        else {
            s++;
            e--;
        }
    }  
    return 1; 
}

//REVERSE A STRING
void reverseStr(char name[], int size) {
    int s = 0 ;
    int e = size - 1;
    while(s<e) {
        // swap(name[s++], name[e--]);

        char temp = name[s];
        name[s] = name[e];
        name[e] = temp;
        s++;
        e--;
    }
}

//REVERSE A STRING -II
void rStr(char name[], int size) {
    int s = 0; 
    int e = size - 1;
    for(int i=0; i<size/2; i++){
        // swap(name[s++], name[e--]);
        char temp = name[i];
        name[i] = name[e];
        name[e] = temp;
        s++;
        e--;
    }
}

//LENGTH OF A STRING
int getLength(char name[]) {
    int cnt = 0;
    for(int i=0; name[i] != '\0'; i++) {
        cnt++;
    }
    return cnt++;
}

//MAXIMUM OCCURING CHARACTER
char getMaxOccChar(string s) {

    int arr[26] = {0};

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        //lowercase
        int number = 0;
        number = ch - 'a';
        int result = arr[number]++;
    }

    //find maximum occuring character
    int maxi = -1, ans = 0;
    for(int i=0; i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];           
        }
    }
    return 'a' + ans;
}

int main() {

    int n;
    cout << "\nEnter the size of the Char => ";
    cin >> n;

    char name[n];
    cout << "\nEnter your name => ";
    cin >> name;

    cout << "\nYour name is => ";
    cout << name << endl;

    // name[2] = '\0';
    // cout << "\nYour name is => " << name << endl;

    int len = getLength(name);
    cout << "\nLength of the string is => " << len << endl;

    reverseStr(name, len);
    cout << "\nYour name(reversed) is => " << name << endl;

    rStr(name, len);
    cout << "\nYour name(reversed) is => " << name << endl;

    if(checkPalindrome1(name, len))
        cout << "\nYes the string is a Palindrome" << endl;
    else    
        cout << "\nNo the string is not a palindrome" << endl;
    cout << endl;

    bool search  = checkPalindrome2(name, len);
    if(search)
        cout << "Palindrome or not : " << search << endl;
    else    
        cout << "Palindrome or not : " << search << endl;
    cout << endl;

    // cout << "CHARACTER IS(toLowerCase) => " << toLowerCase('D') << endl;
    // cout << "CHARACTER IS(toLowerCase) => " << toLowerCase('t') << endl;

    string s;
    cout << "\nEnter the characters in the string => " ;
    cin >> s;
    cout << "\nMaximum no. of occuring character is => " << getMaxOccChar(s) << endl;


    cout << endl;
    return 0;
}