#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void rotateOptimized(vector<int>& nums, int k) {
    k = k % nums.size();

    cout << k << endl;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

void rotate(vector<int>& nums, int k) {
    k = k % nums.size();

    int n = nums.size();
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        if (i < k) {
            result.push_back(nums[n - k + i]);
        } else {
            result.push_back(nums[i - k]);
        }
    }

    nums = result;
}

int main() {

    //vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    //int k = 3;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3; 

    rotate(nums, k);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}