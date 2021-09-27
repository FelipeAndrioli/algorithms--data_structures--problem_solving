#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/*
 * My own solution of 71A problem from Codeforces
 *
 * O(n) solution
 *
 * */

string abbreviate_word(string word) {

    string abbreviated_word = word;

    int word_size = 0;

    for (int i = 1; i < word.length() - 1; i++) {
        word_size++;
    }

    abbreviated_word = word[0] + to_string(word_size) + word[word.length() - 1];

    /*
     * O(1) solution
     *
     * abbreviated_word = word[0] +  to_string(word.length() - 2) + word[word.length() - 1];
     * */

    return abbreviated_word;
}

int main() {

    int n;

    cin >> n;

    string words[n];

    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    for (int i = 0; i < n; i++) {
        if (words[i].length() > 10) {
            cout << abbreviate_word(words[i]) << endl;
        } else {
            cout << words[i] << endl;
        }
    }

    return 0;
}
