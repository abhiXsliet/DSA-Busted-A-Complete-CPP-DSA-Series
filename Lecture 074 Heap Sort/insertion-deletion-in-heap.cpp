//Heap is a ds which is a CBT(complete Binary Tree) that comes with a heap order property
//A CBT is a BT in which all the levels are completely filled except the last level
//nodes always added from the left in CBT or lean towards the left

//Max Heap => Parent is always greater than childs
//Min Heap => Parent is always smaller than childs

//Node -> ith index (For 1-based indexing)
//left child  -> 2*i index
//right child -> (2*i + 1) index
//parent      -> (i/2)index

//Node -> ith index (For 0-based indexing)
//left child  -> 2*i+1 index
//right child -> (2*i + 2) index
//parent      -> (i/2)index

#include<iostream>
using namespace std;

class heap {
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    // TC -> O(log) -> since we are comparing value with i/2 index
    void insert(int val){
        size = size + 1;
        int index = size;
        arr[size] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout << arr[i] << " ";
        }cout << endl;
    }

    // TC -> O(logn)
    void deletefromHeap(){
        if(size == 0){
            cout << "\nNothing to delete";
            return;
        }
        
        //step 1 : put last element into the first index
        arr[1] = arr[size];

        //step 2 : remove last element
        size --;

        //step 3 : take root node to its correct position
        int i = 1;
        while(i < size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }
    }
};

////////////////////////////////////////////////////////////////////////
/// In CBT leaf nodes lies between (n/2 + 1)index to nth index      ////
////////////////////////////////////////////////////////////////////////

// In Heapify fn one have to perform the operations on only 1st to n/2th indexes of nodes

//Time Complexity => O(logn) me heapify sahi jagah pahuncha deti hai
//Build Max heap -> written here for 1-based indexing
void heapify(int arr[], int n, int i){

    int largest = i;
    int left = 2*i; //when left child is 2*i then heapify is written for 1-based indexing
    int right = 2*i+1;

    // left < n for 0-based indexing
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    //largest update hogya hoga toh i ke equal nhi hoga
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); 
    }
}

int main(){
    heap h;
    h.insert(55);
    h.insert(54);
    h.insert(53);
    h.insert(50);
    h.insert(52);
    h.print();    

    h.deletefromHeap();
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //for 1-based indexing -> go from n/2 to 0 -> below written
    //for 0-based indexing -> go from n/2-1 to 0
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);     //O(n) for building heap
    }
    cout << "Printing the array now" << endl;
    for(int i=1; i<=n; i++){
        cout << arr[i] << " ";
    }cout << endl;

    cout << endl;
    return 0; 
}