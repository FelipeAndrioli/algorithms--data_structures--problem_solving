#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string reverseWords(string s) {
    int left = 0;
    int right = 0;
    int n = s.size();

    for (int i = 0; i < n; i++) {

        if (s[i - 1] == ' ' && i != 0) {
            left = i;
        }

        if (s[i] == ' ') {
            right = i - 1;
        } else if (i == n - 1) {
            right = i;
        }

        if (left != right) {
            while (left < right) {
                swap(s[left++], s[right--]);
            }
        }
    } 

    return s;
}

string reverseWordsOptimized(string s) {
    int left = 0;

    for (int i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == ' ') {
            reverse(&s[left], &s[i]);
            left = i + 1;
        }
    } 

    return s;
}

int main() {

    string s = "Let's take LeetCode contest";
    string sa = "Let's take LeetCode contest";
    //string s = "God Ding"; 
    string reversed = reverseWords(s);
    string reversed_sec = reverseWordsOptimized(sa);

    cout << reversed << endl;
    cout << reversed_sec << endl;

    return 0;
}