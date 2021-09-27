#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
    O(n) solution
*/

int calculate_problems(int n, int problems[][3]) {
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (problems[i][0] + problems[i][1] == 2 || problems[i][0] + problems[i][2] == 2 || problems[i][1] + problems[i][2] == 2) {
            result++;
        }
    }    

    return result;
}

int main() {

    int n = 0;

    cin >> n;

    int inputs[n][3];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> inputs[i][j];
        }
    }

    cout << calculate_problems(n, inputs) << endl;

    return 0;
}