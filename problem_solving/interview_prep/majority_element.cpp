#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void find_majority(int array_size, int array[]) {
    
    int count = 0;
    unordered_map<int, int> temp_map;

    for (int i = 0; i < array_size; i++) {
        temp_map[array[i]]++;
    }

    unordered_map<int, int>::iterator it;

    for (it = temp_map.begin(); it != temp_map.end(); it++) {
        if (it->second > array_size / 2) {
            count = 1;
            cout << "Majority element: " << it->first << endl;
            break;
        }
    }

    if (count == 0) {
        cout << "Any majority element was found" << endl;
    }
}

int main() {

    int array[] = {2, 1, 2};
    int array_size = sizeof(array) / sizeof(*array);

    find_majority(array_size, array);

    return 0;
}