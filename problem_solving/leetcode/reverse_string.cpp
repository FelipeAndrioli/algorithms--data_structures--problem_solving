#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverseString(vector<char>& s) {
    //O(1) space
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

void reverseStringIterator(vector<char>& s) {
    //O(n) space
    vector<char> reversed_string;

    int n = s.size() - 1;

    for (int i = 0; i < s.size(); i++) {
        reversed_string.push_back(s[n - i]);
    }

    s = reversed_string;
}

int main() {

    vector<char> s = {'h','e','l','l','o'};
    reverseString(s);

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    cout << endl;

    return 0;
}