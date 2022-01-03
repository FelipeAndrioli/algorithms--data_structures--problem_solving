#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void moveZeroesOptimized(vector<int> &nums) {
    for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
        if (nums[cur] != 0) {
            swap(nums[lastNonZeroFoundAt++], nums[cur]);
        }
    }
}

void moveZeroes(vector<int> &nums) {

    vector<int> zeroes;
    vector<int> numbers;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            zeroes.push_back(nums[i]);
        } else {
            numbers.push_back(nums[i]);
        }
    }

    for (int i = 0; i < zeroes.size(); i++) {
        numbers.push_back(zeroes[i]);
    }

    nums = numbers;
}

int main() {

    vector<int> nums = {0, 1, 0, 2, 0, 3, 0, 4};

    moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

    return 0;
}