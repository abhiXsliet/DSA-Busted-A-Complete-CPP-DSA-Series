#include<bits/stdc++.h>
using namespace std;

int countInversion(vector<int>& arr, int size) {
    int cnt = 0;
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[i] > arr[j]) cnt ++;
        }
    }
    return cnt;
}

int merge(vector<int>& arr, int start, int mid, int end) {
    vector<int>temp;
    int left = start;
    int right = mid+1;
    int cnt = 0;
    while(left <= mid && right <= end) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;

        } else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    } 
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= end) {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=start; i<=end; i++) {
        arr[i] = temp[i-start];
    }

    return cnt;
}

int mergeSort(vector<int>& arr, int start, int end) {
    //base case
    int cnt = 0;
    if(start >= end) return 0;
    int mid = start + (end - start)/2;
    cnt += mergeSort(arr, start, mid);
    cnt += mergeSort(arr, mid+1, end);
    cnt += merge(arr, start, mid, end);
    return cnt;
}

int main() {
    vector<int> arr = {10, 9, 8, 7};
    int n = arr.size();
    int cnt = 0;
    // cout << countInversion(arr, n);
    cout << endl;

    cnt = mergeSort(arr, 0, n-1);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
    cout << cnt ;
    return 0;
}