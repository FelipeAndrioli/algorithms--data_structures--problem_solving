#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int ALPHABET_SIZE = 26;

/*
    Trie is an efficient information re Trieval data structure. Using Trie, search complexities
    can be brought to optimal limit(key length). If we store keys in bynary search tree, a
    well balanced BST will need time proportional to M * log N, where M is maximum string        
    length and N is number of keys in tree. Using Trie, we can search the key in O(M) time.
    However the penalty is on Trie storage requirements.

    Every node of Trie consists of multiple branches. Each branch represents a possible
    character of keys. We need to mark the last node of every key as end of word node. We
    need to mark the last node of every key as end of word node. A Trie node field 
    isEndofWord is used to distinguish the node as end of word node. A simple structure
    to represent nodes of the English alphabet can be as following:

    struct TrieNode {
        struct TrieNode *children[ALPHABET_SIZE];
        bool isEndofWord;
    }    

    Inserting a key into Trie is a simple approach. Every character of the input key is
    inserted as an individual Trie node. Note that the children is an array of pointers
    (or references) to next level trie nodes. They key character acts as an index into 
    the array children. If the input key is new or an extension of the existing key,
    we need to construct non-existing nodes of the key, and mark end of the word for     
    the last node. If the input key is a prefix of the existing key in Trie, we 
    the last node of the key as the end of a word. The key length determines the Trie depth.

    Searching for a key is similar to insert operation, however, we only compare the 
    characters and move down. The search can terminate due to the end of a string or lack
    of key in the trie. In the former case, if the isEndofWord field of the last node is
    true, then the key exists in the trie. In the second case, the search terminates
    without examining all the characters of the key, since the key is not presented in
    the trie.

    Example:

                       root
                    /   \    \
                    t   a     b
                    |   |     |
                    h   n     y
                    |   |  \  |
                    e   s  y  e
                 /  |   |
                 i  r   w
                 |  |   |
                 r  e   e
                        |
                        r

    In the example, every character if of type trie_node_t. For example, the root is of
    type trie_node_t, and it's chidlren a, b and t are filled, all other nodes of root
    will be NULL. Similarly, "a" at the next level is having only one child("n"), all
    other children are NULL.

    Insert and search costs O(key_length), however the memory requirements of Trie is
    O(ALPHABET_SIZE * key_length * N) where N is number of keys in Trie. There are 
    efficient representation of trie nodes (compressed trie, ternary search tree, etc) to
    minimize memory requirements of trie.

*/

// Trie node
struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];

    bool isEndofWord;
};

// Initialize new trie node (initialized as NULLs)
struct TrieNode *newNode() {
    struct TrieNode *pNode = new TrieNode;

    pNode->isEndofWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';

        cout << "Inserting index: " << index << endl;

        if (!pCrawl->children[index]) {
            pCrawl->children[index] = newNode();
        }

        pCrawl = pCrawl->children[index];
    }

    pCrawl->isEndofWord = true;
}

// Returns true if the key is present in the trie, else false
bool search(struct TrieNode *root, string key) {
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            return false;
        }

        pCrawl = pCrawl->children[index];
    }
 
    return (pCrawl->isEndofWord);
}

int main() {

    string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    int keys_size = sizeof(keys) / sizeof(*keys);

    struct TrieNode *root = newNode();

    for (int i = 0; i < keys_size; i++) {
        insert(root, keys[i]);
    }

    search(root, "the") ? cout << "Yes" << endl : cout << "No" << endl;
    search(root, "these") ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}