#include<iostream>
#include<queue>
using namespace std;

//max heap
void heapify(int arr[], int n, int i){
    int largest = i;     // code written in 1-based indexing
    int left  = 2*i;     //for 0-based indexing -> 2*i + 1;
    int right = 2*i + 1; //for 0-based indexing -> 2*i + 2;

    if(left <= n && arr[largest] < arr[left]){ //1-based indexing left<=n
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        //step1 : swap
        swap(arr[size], arr[1]);
        size --;

        //step2
        heapify(arr, size, 1);
    }
}

int main(){
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //heap creation
    for(int i=1; i<=n; i++){
        heapify(arr, n, i);
    }

    cout << "\nPrinting the array " << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    //Heap Sort
    heapSort(arr, n);
    cout << "\nPrinting sorted array using Heap Sort " << endl;
    for(int i=1; i<=n ; i++){
        cout << arr[i] << " ";
    }cout << endl;

    ////////////////////////////
    /////////   STL   //////////
    ////////////////////////////
    
    //Using priority queue we can make max and min heap
    priority_queue<int> pq;

    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);

    cout << "\nElement at top => " << pq.top() << endl;
    pq.pop();

    cout << "\nElement at top => " << pq.top() << endl;
    cout << "\nSize is " << pq.size() << endl;

    if(pq.empty()){
        cout << "pq is empty" << endl;
    }else{
        cout << "pq is not empty" << endl;
    }

    //min heap using priority queue
    priority_queue<int, vector<int>, greater<int> > minheap;

    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout << "\nElement at top => " << pq.top() << endl;
    pq.pop();

    cout << "\nElement at top => " << pq.top() << endl;
    cout << "\nSize is " << pq.size() << endl;

    if(pq.empty()){
        cout << "pq is empty" << endl;
    }else{
        cout << "pq is not empty" << endl;
    }

    cout << endl;
    return 0;
}

//Time complexity of heap sort is => O(nlogn)
//work you do in heapSort
//1. build heap , 2.heapsort logic we used there