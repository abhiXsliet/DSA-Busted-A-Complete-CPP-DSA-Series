//STANDARD TEMPLATE LIBRARY
#include<iostream>
using namespace std;
/* 

//array data structure 
#include<array> //array's library


int main(){
    int basic[3] = {1, 2, 3};

    array<int,4> a = {1, 2, 3, 4};

    //uper wala aur niche wala array me ye difference hai ki niche wala stl ki implementation uper wala basic array se hi hoti hai
    //array stl ki implemetation fixed size ki static array se hoti hai
    //stl array is also an static array that's why we don't use it in cp


    int size = a.size();

    for(int i=0; i<size; i++){
        cout << a[i] << endl;
    }

    cout << "Element at 2nd index ==> " << a.at(2) << endl;

    cout << "Empty or not ==> " << a.empty() << endl;

    cout << "First Element ==> " << a.front() << endl;
    cout << "last Element ==> " << a.last() << endl;

    //every operation performed here(a.at, a.front, a.empty, a.front/last) at o(1) time complexity;
  
} 
*/

/* 
//vector (second data structure)
//It is a dynamic array where data is similarly stored at a continouous memeory allocation like static array
//but when the size become full it dump the previous array and creates the new arrays of double size and copy all elements of previous array into the newly made double size array and dump the previous array;


#include<vector>

int main(){

    vector<int>v;                                   
    cout << "Capacity-> " << v.capacity() << endl; //capacity means kitni memory array ko assign hui padi hai;

    v.push_back(1);
    cout << "capacity-> " << v.capacity() << endl;

    v.push_back(2);
    cout << "capacity-> " << v.capacity() << endl;

    v.push_back(3);
    cout << "capacity-> " << v.capacity() << endl;
    cout << "size -> " << v.size() << endl;       // size tells us the total no. of elements present inside an array;


    cout << "Element at 2nd index-> " << v.at(2) <<endl;
    

    cout << "front-> " << v.front() << endl;
    cout << "back-> " << v.back() << endl;

    
    cout << "before pop " << endl;
    for(int i:v){
        cout << i << " " ;
    }cout << endl;

    v.pop_back();
    for(int i:v){
        cout << i << " ";
    }cout << endl;

//when we use clear operation on a vector then only the size of the vector becomes zero not the capacity(capacity of the vector remains the same as it is)

    cout << "before clear size-> " << v.size() << endl;
    v.clear();

    cout << "after clear size-> " << v.size() << endl;

    //by using .begin() operation we can find the starting iterator;


//other way of initializing a vector;
cout<<"\n\n\n" ;
    vector<int> a(5,1); //here 5 is the size of the vector and initializing all elements of the vector a with 1;

    cout << "printing a => ";
    for(int i:a){
        cout << i << " ";
    }

cout << endl << endl;
    vector<int> last(a); //copying all elements of a into the last vector;
    
    cout << "printing last => ";
    for(int i:last){
        cout << i << " ";
    }

cout << endl << endl;

}
*/


/* 
//doubly ended queue or deque (pronounced as 'deck');
#include<deque>

//perform all previous opr.
//it is dynamic in nature since it can reduce or enlarge their size


int main(){
    deque<int> d;
    
    d.push_back(1);
    d.push_front(2);
    d.push_back(5);
    d.push_back(6);
    for(int i:d){
        cout << i << " ";
    }

    
    // d.pop_back();
    // cout << endl;
    // for(int i: d){
    //     cout << i << " ";
    // }

    // d.pop_front();
    // cout << endl;
    // for(int i:d){
    //     cout << i << " ";
    // }

    
    cout << endl;
    cout << "printing first Index element -> " << d.at(1) << endl;
    cout << "front -> " << d.front() << endl;
    cout << "back -> " << d.back() << endl;

    cout << "Empty or not -> " << d.empty() << endl;

    cout << "before erase ==> " << d.size() << endl;

    d.erase(d.begin(), d.begin()+1); //yaha pr hame btana padta hai kaha se kaha tak delete krwana hai

    cout << "after erase ==> " << d.size() << endl; //yaha pr bhi same erase function ke baad size zero ho jati hai lekin the memory capacity jitni starting me thi utni hi hogi ushpe koi fark nhi padega erase function 

    for(int i:d){
        cout << i << " ";
    }

    //TC of all operations are o(1) but 
    //TC of erase operation will be o(n) since we are traversing through each element;

}

*/

/* 
//list 
#include<list>

//list stl is made using doubly linked list(it has two pointer one for front and other for back)

int main(){
    list<int> l;

    list<int> n(l); //copying list (l) into a new list (n)

    list<int> ln(5,100); //5 elements are present are there in the list and every single element is initialised with 100
    
    cout << "\nprinting ln -> ";
    for(int i:ln){
        cout << i << " ";
    }cout << endl ;

    l.push_back(1);
    l.push_front(2);
    //same for pop_back/front
    
    cout << "\nprinting push_back/front element -> ";
    for(int i:l){
        cout << i << " ";
    }

    cout << endl;

    l.erase(l.begin());
    cout << "after erase => " ;
    for(int i:l){
        cout << i << " ";
    }

    cout << "\nsize of list -> " << l.size() << endl << endl;
}

*/

/* 
//stack 

#include<stack>

int main(){
    
    stack<string> s;

    s.push("Abhishek");
    s.push("Kumar");
    s.push("Sharma");

    cout << "Top Element -> " << s.top() << endl;

    s.pop();
    cout << "Top Element -> " << s.top() << endl;

    cout << "size of stack -> " << s.size() << endl;

    cout << "Empty or not -> " << s.empty() << endl;
}


*/


/* 
//Queue 

#include<queue>

int main(){

    queue<string> q;

    q.push("Abhishek");
    q.push("Kumar");
    q.push("Sharma");

    cout << "Size before pop -> " << q.size() << endl;

    cout << "First Element -> " << q.front() << endl;

    q.pop();
    cout << "Fist Element -> " << q.front() << endl;

    cout << "Size after pop -> " << q.size() << endl;

}

*/

/* 

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

    cout << "(mini) Khali hai kya bhai?? => " <<mini.empty() << endl;
    cout << "(maxi) Empty or not => " << maxi.empty() << endl << endl ; 
}


*/


/* 

//set

//set stores unique element (matlab ye hai ki har element ko ekhi baar store karta hai for e.g., agar aap 5-baar 5 daalte ho to set ekhi baar 5 ko store krega);
//Modification in set is not possible, you can either insert or delete an element.
//set se elements sorted order me return hote hai
//set is slow as compared to unordered set
//When we fetch elements from an unordered list then it returns into unordered form

#include<set>

int main(){
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(6);
    s.insert(6);
    s.insert(0);
    s.insert(0);
    s.insert(0);

    for(auto i : s){
        cout << i << endl ;
    }cout << endl;

    set<int> :: iterator it = s.begin();
    it++;

    s.erase(it);

    for(auto i : s){
        cout << i << endl ;
    }cout << endl;

    cout << "-5 is present or not -> "<< s.count(-5) << endl;

    set<int> :: iterator itr = s.find(5);
    for(auto it = itr; it!=s.end(); it++){
        cout << *it << " ";
    }cout << endl << endl;


    //Time complexity of insert/ find/ erase or count ==> o(logn)
    //Time complexity of size/ end/ begin / empty ==> o(1)
}


*/


/* 
//map (44:00)

#include<map>

//same key do value ko point nhi krega (for e.g., love is pointing to scorpio and babbar is pointing to scorpio, do alag alag key same value ko point kr sakta hai lekin ekhi key do alag alag value ko point nhi kr sakta jaise me love is pointing to scorpio, also love is pointing to verna, ye galat hai aisa nhi hoga)
//sorted in map case but random in unordered map

int main(){
    map<int,string> m;

    m[1] = "sharma"; //yaha 1 mera key hai aur sharma mera value hai;
    m[13] = "kumar";
    m[2] = "abhishek";
    //other way of inserting
    m.insert( {5, "bheem"}); 

    cout << "\nBefore erase:- " << endl;
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }

    cout << "\nfinding 13 -> " << m.count(13) << endl;
    cout << "finding -13 -> " << m.count(-13) << endl;

   // m.erase(13);
    cout << "\nAfter erase:-" << endl;
    for(auto i:m){
        cout << i.first << " " << i.second << endl;
    }

    cout << endl ;
    auto it = m.find(5);
    for(auto i = it; i!=m.end(); i++){
        cout << (*i).first << endl;
    }

    //Time complexity of insert/erase/find/count => o(logn);
    //Time complexity of search => o(logn) since this map is implemented using binary tree  
    //O(1) in unordered map because this map is implemented by using hash table


}

*/


//ALGORITHMS

#include<algorithm>
#include<vector>

int main(){
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);

    cout << "\nFinding 6 -> " << binary_search(v.begin(), v.end(), 6) << endl;

    cout << "lower bound -> " << lower_bound(v.begin(), v.end(), 6)-v.begin() << endl;
    cout << "upper bound -> " << upper_bound(v.begin(), v.end(), 4)-v.begin() << endl;

    int a = 3;
    int b = 5;

    cout << "max -> " << max(a,b) << endl;
    cout << "min -> " << min(a,b) << endl;

    swap(a,b);
    cout << endl << "a -> " << a << endl;

    string abcd = "abcd";
    reverse(abcd.begin(), abcd.end());
    cout << "string -> " << abcd << endl;

    rotate (v.begin(), v.begin()+1, v.end());
    cout << "after rotate " << endl;
    for(int i: v){
        cout << i << " ";
    }cout << endl << endl;

    sort(v.begin(), v.end());
    //working of based on intro sort which is running behind this sort function
    //intro sort is the combination of quick sort , heap sort and insertion sort

    for(int i: v){
        cout << i << " " ;
    }cout << endl << endl;
}