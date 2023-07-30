// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/



#include<bits/stdc++.h>
using namespace std;

// TC => O(N^2 * k)
// SC => O(1)
int sumOfKSubArray_brute(vector<int>& arr, int n, int subArrSize) {
    int sum = 0;
    cout << "\nGenerating subarray of size-" << subArrSize << " is: " << endl;
    for(int i = 0; i < n; i++) {
        int length = 0;
        for(int j = i; j < n; j++) {
            length++;
            if(length == subArrSize) {
                      
                int maxi = INT_MIN;
                int mini = INT_MAX;  
                cout << "{ ";

                for(int k = i; k <= j; k++) {
                    cout << arr[k];
                    if(k != j) cout  << ", " ;

                    maxi = max(maxi, arr[k]);
                    mini = min(mini, arr[k]);
                }
                cout << " }" ;
                cout << endl;

                sum += (maxi + mini);
            }

        }
    }
    return sum;
}

// TC => O(N)
// SC => O(k) where k is the space used by the subArraySize
int sumOfKSubArray_optimal(vector<int>& arr, int n, int subArraySize) {
    deque<int> S(subArraySize), G(subArraySize);
    // Process first window of size K
    int i = 0;
    int sum = 0;
    for ( ; i < subArraySize; i++) {
        while( !S.empty() && arr[S.back()] >= arr[i] )
            S.pop_back();
        while( !G.empty() && arr[G.back()] <= arr[i] )
            G.pop_back();

        S.push_back(i);
        G.push_back(i);
    }
 
    // process rest of the array elements
    for( ; i < n; i++) {
        // Element at the front of deque's are largest and smallest respectively
        sum += arr[S.front()] + arr[G.front()];

        // Remove all elements which are out of this window
        while( !S.empty() && S.front() <= i-subArraySize )
            S.pop_back();
        while( !G.empty() && G.front() <= i-subArraySize ) 
            G.pop_back();

        // Remove all greater element that are useless
        while( !S.empty() && arr[S.back()] >= arr[i] )
            S.pop_back();
        while( !G.empty() && arr[G.back()] <= arr[i] )
            G.pop_back();

        G.push_back(i);
        S.push_back(i);
    }
 
    // Sum of minimum and maximum element of last window
    sum += arr[S.front()] + arr[G.front()];
 
    return sum;
}

int main() {
    vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    int n = sizeof(arr)/arr[0];
    cout << "\nSum of maximum and minimum element of subarray of size-" << k << " is : " 
    << sumOfKSubArray_brute(arr, n, k) << endl;

    cout << "\nSum of maximum and minimum element of subarray of size-" << k << " is : " 
    << sumOfKSubArray_optimal(arr, n, k) << endl;

    cout << endl;
    return 0;
}