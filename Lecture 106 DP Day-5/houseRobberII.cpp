//https://www.codingninjas.com/codestudio/problems/house-robber_839733
//Time Complexity will be O(N)
//Space Complexity will be O(N)

#include <bits/stdc++.h> 
using namespace std;

long long int solveSpaceOpt(vector<int>& valueInHouse) {
    int n = valueInHouse.size();

    long long int prev1 = valueInHouse[0]; 
    long long int prev2 = 0;

    for(int i=1; i<n; i++) {
        long long int incl = prev2 + valueInHouse[i];
        long long int excl = prev1 + 0;
        long long int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1)
        return valueInHouse[0];

    vector<int>first, second;
    for(int i=0; i<n; i++) {
        if(i != n-1)
            first.push_back(valueInHouse[i]);

        if(i != 0)
            second.push_back(valueInHouse[i]);
    }

    return max(solveSpaceOpt(first), solveSpaceOpt(second));
}