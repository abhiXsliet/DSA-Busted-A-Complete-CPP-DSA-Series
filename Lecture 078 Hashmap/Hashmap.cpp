//What is Hashmaps?
//A type of DS that basically maps keys to values and every key should be unique
//Time complexity will be O(1) for insertion/deletion/searching operations

#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {
    //creation
    // unordered_map<string, int> m;
    map<string, int> m;

    //INSERTION

    //1
    pair<string, int> p = make_pair("Abhishek", 4);
    m.insert(p);

    //2
    pair<string,int> pair2("love", 5);
    m.insert(pair2);

    //3
    m["mera"] = 1; //entry created here

    //4
    m["mera"] = 3; //entry got updated here

    //SEARCH
    cout << m["mera"] << endl;
    cout << m.at("love") << endl;
    cout << m.at("Abhishek") << endl; 
    // cout << m.at("babbar") << endl;  //error-> out of range

    // cout << m.at("unKnownKey") << endl;
    cout << m["unKnownKey"] << endl; //entry is getting created for key unKnownKey with value 0 [unKnownKey = 0]
    cout << m.at("unKnownKey") << endl; //refering previously created key-value pair of unKnownKey

    //SIZE
    cout << m.size() << endl; //no. of total entries into the map

    //TO CHECK PRESENCE
    cout << m.count("bro") << endl; //count the total no. of entries into the map
    cout << m.count("love") << endl;

    //ERASE
    m.erase("love"); //erasing entry of love from the map
    cout << m.size() << endl;

    //ACCESSING EACH ELEMENT OF MAP -> NO ORDER 
    // for(auto i:m){
    //     cout << i.first << " " << i.second << endl;
    // }

    //ITERATOR -> NO ORDER 
    // unordered_map<string, int> :: iterator it = m.begin();
    map<string, int>::iterator it = m.begin();

    while(it != m.end()){
        cout << it->first << " " << it->second << endl;
        it++;
    }

    //BUCKET ARRAY  -> key-value pair is stored in a bucket(it is arranged in an array or a list). Each bucket is assigned an index based on hash value of its key.
    //Hash Function -> Hash Code    -> provide a value (int)
    //              -> compression function -> compress the int value

    //Some Hash codes
    // -> Identity function -> Whatever gives in input gives as corresponding output
    // Why we need ?
    // -> For conversion to int
    // -> Uniform Distribution

    // Collision Handling
    //      -> Open Hashing  -> Head of Linked List is stored in the block -> (aka separate chaining)
    //      -> Open Addressing -> Hi(a) = h(a) + Fi(a) 
    //              -> Linear Probing -> Fi = i
    //              -> Quadratic Probing
    

    // Load Factor = n/b where b=total no. of boxes and n=total no. of entries into the boxes
    // we always ensure n/b < 0.7
    // if n is increasing then we have to increase the no. of total available boxes (Rehasing)
    

    return 0;
}