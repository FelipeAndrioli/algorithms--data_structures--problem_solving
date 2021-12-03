#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &nums) {

    if (nums.size() == 0) {
        return 0;
    }

    int product = nums[0];
    int bigger_product = nums[0];
    int smaller_product = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < 0) {
            swap(smaller_product, bigger_product);
        }

        smaller_product = min(nums[i], negative_product * nums[i]);
        bigger_product = max(nums[i], positive_product * nums[i]);
        product = max(bigger_product, product);
    } 

    return product;
}

int main() {

    //vector<int> nums = {2, 3, -2, 4};
    vector<int> nums = {-2, 0, 1};
    //vector<int> nums = {-4, -3};

    cout << maxProduct(nums) << endl;
    
    return 0;
}