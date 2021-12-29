#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int version) {
    return 0;
}

int firstBadVersion(int n) {
    int left = 1;
    int right = n;
    int mid;

    while (left < right) {
        mid = left + (right - left) / 2;

        if (!isBadVersion(mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {

    int n = 5;
    int bad = 4;

    cout << "Looking for the first bad version..." << endl;
    cout << firstBadVersion(n) << endl;

    return 0;
}