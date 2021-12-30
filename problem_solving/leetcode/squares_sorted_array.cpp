#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> sortedSquaresOptimized(vector<int>& A) {
    vector<int> res(A.size());
    int l = 0, r = A.size() - 1;
    for (int k = A.size() - 1; k >= 0; k--) {
        if (abs(A[r]) > abs(A[l])) res[k] = A[r] * A[r--];
        else res[k] = A[l] * A[l++];
    }
    return res;
}

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result;
    vector<int> temp_result;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {

        int left_square = nums[left] * nums[left];
        int right_square = nums[right] * nums[right];

        if (right_square > left_square) {
            temp_result.push_back(right_square);
            right--;
        } else if (left_square > right_square) {
            temp_result.push_back(left_square);
            left++;
        } else if (left_square == right_square && left != right) {
            temp_result.push_back(left_square);
            temp_result.push_back(right_square);
            right--;
            left++;
        } else if (left_square == right_square && left == right) {
            temp_result.push_back(left_square);
            left++;
        }
    }

    for (int i = 0; i < temp_result.size(); i++) {
        result.push_back(temp_result[temp_result.size() - i - 1]);
    }

    return result;
}

int main() {

    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> result = sortedSquaresOptimized(nums);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    cout << endl;

    return 0;
}