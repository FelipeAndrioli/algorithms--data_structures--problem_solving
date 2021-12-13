#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxPower(string s) {

    if (s.length() == 0 || s.length() == 1) {
        return s.length();
    }
    
    char current_char = s[0];
    char next_char = s[1];

    int main_count = 1;
    int temp_count = 1;

    if (s.length() == 2 && current_char == next_char) {
        return 2;
    }
    
    for (int i = 2; i < s.length() + 1; i++) {

        if (current_char == next_char) {
            temp_count++;
        } else {
            temp_count = 1;
        }

        main_count = max(main_count, temp_count);
        current_char = next_char;
        next_char = s[i];
    }

    return main_count;
}

int main() {
    string s = "abcdd";

    cout << maxPower(s) << endl;

    return 0;
}