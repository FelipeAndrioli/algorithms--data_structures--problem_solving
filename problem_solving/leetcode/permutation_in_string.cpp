#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool checkInclusion(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    if (n > m) {
        return false;
    }

    vector<int> v1(26, 0);
    vector<int> v2(26, 0);

    for (int i = 0; i < n; i++) {
        v1[s1[i] - 'a']++;
        v2[s2[i] - 'a']++;
    }

    for (int i = 0; i < m - n; i++) {
        if (v1 == v2) {
            return true;
        }

        v2[s2[i] - 'a']--;
        v2[s2[i + n] - 'a']++;
    }
    return v1 == v2;
}

int main() {

    string s1 = "ab";
    //string s2 = "eidboaoo";
    string s2 = "eidbaooo";

    bool inclusion = checkInclusion(s1, s2);

    if (inclusion) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}