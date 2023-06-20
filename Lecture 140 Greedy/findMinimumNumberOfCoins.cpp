//https://www.codingninjas.com/codestudio/problems/find-minimum-number-of-coins_975277

#include <bits/stdc++.h> 
using namespace std;

int findMinimumCoins(int amount) 
{
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int cnt = 0;
    int n = 9;
    
    for(int i=n-1; i>=0; i--) {
        while(amount >= deno[i]) {
            amount -= deno[i];
            cnt++;
        }
    }
    return cnt;
}


