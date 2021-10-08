#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        vector<int> sumZero(int n);
};

vector<int> Solution::sumZero(int n) {
    
    vector<int> answer;

    if (n % 2 == 1) {
            answer.push_back(0);
    }

    for (int i = 0; i < n / 2; i++) {
        answer.push_back(i + 1);
        answer.push_back(-i - 1);
    }

    return answer;
}

int main() {

    Solution solution;
    vector<int> answer = solution.sumZero(3);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }

    cout << endl;

    return 0;
}