#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch) {
            data = ch;
            for(int i=0; i<26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
            root = new TrieNode('\0');
        }

        void insertUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                root -> isTerminal = true;
                return;
            }

            //assuming the words to be CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }
            else{
                //absent
                child = new TrieNode(word[0]);
                root -> children[index] = child;
            }

            //RECURSION
            insertUtil(child, word.substr(1));
        }

        void insertWord(string word) {
            insertUtil(root, word);
        }

        bool searchUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                return root -> isTerminal;
            }

            //assuming the words to be CAPS
            int index = word[0] - 'A';
            TrieNode* child;

            //present
            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }
            else {
                //absent
                return false;
            }

            //RECURSION
            return searchUtil(child, word.substr(1));
        }

        bool searchWord(string word) {
            return searchUtil(root, word);
        }

        void deleteUtil(TrieNode* root, string word) {
            //base case
            if(word.length() == 0) {
                root -> isTerminal = false;
                return ;
            }

            int index = word[0] - 'A';
            TrieNode* child;

            if(root -> children[index] != NULL) {
                child = root -> children[index];
            }
            else {
                cout << "Word is not available" << endl;
            }

            //RECURSION
            deleteUtil(child, word.substr(1));
        }

        void deleteWord(string word) {
            deleteUtil(root, word);
        }
};

int main() {
    Trie *t = new Trie();

    t->insertWord("DO");
    t->insertWord("TIME");
    t->insertWord("DOING");
    
    cout << "\nPresent or Not ? : " << t->searchWord("TIME") << endl;
    cout << "\nPresent or Not ? : " << t->searchWord("DOI") << endl;
    cout << "\nPresent or Not ? : " << t->searchWord("DOING") << endl;

    t->deleteWord("DO");
    t->deleteWord("DOING");
    cout << "\nPresent or Not ? : " << t->searchWord("DO") << endl;
    cout << "\nPresent or Not ? : " << t->searchWord("DOING") << endl;


    cout << endl;
    return 0;
}