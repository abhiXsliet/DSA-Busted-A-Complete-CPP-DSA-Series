//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;

//Priority Queue
#include<queue>

int main(){
    //max heap
    priority_queue<int> maxi;

    //min heap
    priority_queue<int,vector<int>, greater<int> > mini;

    maxi.push(1);
    maxi.push(3);
    maxi.push(2);
    maxi.push(0);
    maxi.push(5);

    cout << "size -> " << maxi.size() << endl;

    int n = maxi.size();
    for(int i=0; i<n; i++){
        cout << maxi.top() << " ";
        maxi.pop();
    }cout << endl;


    mini.push(6);
    mini.push(1);
    mini.push(0);
    mini.push(4);
    mini.push(3);

    int m = mini.size();
    for(int i=0; i<m; i++){
        cout << mini.top() << " ";
        mini.pop();
    }
    cout << endl;

    cout << "(mini) Khali hai kya bhai?? => " << mini.empty() << endl;
    cout << "(maxi) Empty or not => " << maxi.empty() << endl;


    cout << endl;
    return 0;
}
