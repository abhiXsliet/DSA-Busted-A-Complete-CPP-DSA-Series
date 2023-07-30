//https://www.codingninjas.com/codestudio/problems/implement-a-phone-directory_1062666


#include<bits/stdc++.h>
using namespace std;


class TrieNode{
    public:
        char data;
        TrieNode* children[26];
        bool isTerminate;

        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminate = false;
        }
};

class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string str) {
            //base case
            if(str.length() == 0) {
                root -> isTerminate = true;
                return;
            }

            int index = str[0]-'a';
            TrieNode* child;

            //present
            if(root->children[index] != NULL) {
                child = root->children[index];
            }
            else{
                //absent
                child = new TrieNode(str[0]);
                root->children[index] = child;
            }

            //recursion 
            return insertUtil(child, str.substr(1));
        }

        void insertStr(string str) {
            insertUtil(root, str);
        }

        void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
            if(curr -> isTerminate) {
                temp.push_back(prefix);
            }

            for(char ch = 'a'; ch <= 'z'; ch++) {
                TrieNode* next = curr -> children[ch-'a'];

                if(next != NULL) {
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string>> getSuggestions(string str) {
            TrieNode* prev = root;
            string prefix = "";
            vector<vector<string>> output;

            for(int i=0; i<str.length(); i++) {
                char lastCh = str[i];

                prefix.push_back(lastCh);

                //check for the lastCh
                TrieNode* curr = prev->children[lastCh-'a'];

                //if not found
                if(curr == NULL) {
                    break;
                }

                //if found
                vector<string>temp;

                printSuggestions(curr, temp, prefix);
                output.push_back(temp);

                temp.clear();
                prev = curr;
            }
            return output;
        }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of trie
    Trie* t = new Trie();

    //insert all contacts in trie
    for(int i=0; i<contactList.size(); i++) {
        string str = contactList[i];
        t->insertStr(str);
    }

    //return ans
    return t->getSuggestions(queryStr);

}