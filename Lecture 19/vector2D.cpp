#include<bits/stdc++.h>
using namespace std;

int main() {
    //declare
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    //print
    for(int i = 0; i <arr.size(); i++) {
        cout << arr[i] << " ";
    }

    cout << endl << endl;

    vector<vector<int>> arrays;
    arrays.push_back(vector<int>());
    arrays.push_back(vector<int>());
    arrays.push_back(vector<int>());
    arrays.push_back(vector<int>());

    arrays[0].push_back(10);
    arrays[0].push_back(20);
    arrays[0].push_back(30);
    arrays[1].push_back(40);
    arrays[1].push_back(40);
    arrays[1].push_back(40);

    for(int i = 2; i <arrays.size()-1; i++) {
        vector<int>temp = {13, 28, 28};
        for(int j = 0; j < arrays[i-2].size(); j++){
            arrays[i].push_back(temp[j]);            
        }
    }


    cout << "[ ";
    for(int i = 0; i < arrays.size(); i++) {
        cout << "{ ";
        for(int j = 0; j < arrays[i].size(); j++) {
            cout << arrays[i][j] << " " ;
        }
        cout << " } ";
    }
    cout << " ]";


    return 0;
}