#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int ALPHABET = 26;

class TrieNode {
    public:
        TrieNode *children[ALPHABET];
        bool isEndOfWord;

        TrieNode() {
            isEndOfWord = false;

            for (int i = 0; i < ALPHABET; i++) {
                children[i] = NULL;
            }
        }
};

class Trie {
    private:
        TrieNode *root;
    public:
        Trie() {
            root = new TrieNode();
        }

        void insert(string word) {

            TrieNode *pCrawl = root;

            for (int i = 0; i < word.length(); i++) {
                int index = word[i] - 'a';

                if (!pCrawl->children[index]) {
                    pCrawl->children[index] = new TrieNode();
                }

                pCrawl = pCrawl->children[index];
            }

            pCrawl->isEndOfWord = true;
        }

        bool search(string word) {

            TrieNode *pCrawl = root;

            for (int i = 0; i < word.length(); i++) {
                int index = word[i] - 'a';

                if (!pCrawl->children[index]) {
                    return false;
                }

                pCrawl = pCrawl->children[index];
            }

            return (pCrawl->isEndOfWord);
        }

        bool startsWith(string prefix) {

            TrieNode *pCrawl = root;

            for (int i = 0; i < prefix.length(); i++) {
                int index = prefix[i] - 'a';

                if (!pCrawl->children[index]) {
                    return false;
                }

                pCrawl = pCrawl->children[index];
            }

            return true;
        }
};

int main() {

    Trie *trie = new Trie();
    trie->insert("apple");
    trie->search("apple") ? cout << "True" << endl : cout << "False" << endl;   // return True
    trie->search("app") ? cout << "True" << endl : cout << "False" << endl;     // return False
    trie->startsWith("app") ? cout << "True" << endl : cout << "False" << endl; // return True
    trie->insert("app");
    trie->search("app") ? cout << "True" << endl : cout << "False" << endl;     // return True

    return 0;
}