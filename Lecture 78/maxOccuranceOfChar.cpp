#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(string str)
{
    unordered_map<char, int> map;

    for(int i=0; i<str.size(); i++) {
        map[str[i]]++;
    }

    int maxi = INT_MIN;

    for(pair<char, int>p: map) {
        if(p.second > maxi) {
            maxi = p.second;
        }
    }

    // for(auto i : map) {
    //     if(maxi < i.second) 
    //         maxi = i.second;
    // } 
    
    return maxi;  
}


int main() {
    string str;
    cout << "\nEnter a string => " ;
    cin >> str;

    int ans = maximumFrequency(str);
    cout << "Maximum occurance of character is : " << ans << endl;

    return 0;
}