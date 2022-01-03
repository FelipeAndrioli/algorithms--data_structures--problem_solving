#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {

    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        if (nums[left] + nums[right] == target) {
            return {left + 1, right + 1};
        } else if (nums[left] + nums[right] > target) {
            right--;
        } else {
            left++;
        }
    }

    return {};
}

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " | ";
    }

    cout << endl;

    return 0;
}