#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstringOptimized(string s) {
    int n = s.length();

    if (n == 0) {
        return 0;
    }

    set<char> st;
    int max_size = 0;
    int i = 0;
    int j = 0;

    while (j < n) {
        if (st.count(s[j]) == 0) {
            st.insert(s[j]);
            max_size = max(max_size, (int)st.size());
            j++;
        } else {
            st.erase(s[i]);
            i++;
        }
    }

    return max_size;
}

int lengthOfLongestSubstring(string s) {
    int result = 0;
    int temp_result = 0;
    int repeat = 0;
    string sub_string;

    for (int i = 0; i < s.length(); i++) {
        sub_string.push_back(s[i]);
        temp_result = sub_string.length();
        repeat = 0;

        for (int j = i + 1; j < s.length(); j++) {
            for (int k = 0; k < sub_string.length(); k++) {
                if (s[j] == sub_string[k]) {
                    repeat = 1;
                }
            }

            if (repeat == 1) {
                break;
            } else if (repeat == 0) {
                temp_result++;
                sub_string.push_back(s[j]);
            }
        }

        if (temp_result > result) {
            result = temp_result;
        }

        sub_string.clear();
    }

    return result;
}

int main() {

    string s = "pwwkew";

    cout << lengthOfLongestSubstringOptimized(s) << endl;

    return 0;
}