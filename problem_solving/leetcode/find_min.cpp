#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums) {
	if (nums.size() == 0) {
		return -1;
	}

	if (nums.size() == 1) {
		return nums[0];
	}

	int left = 0;
	int right = nums.size() - 1;

	while (left < right) {
		int mid = left + (right - left) / 2;
		
		if (mid > 0 && nums[mid] < nums[mid - 1]) {
			return nums[mid];
		} else if (nums[left] <= nums[mid] && nums[mid] > nums[right]) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return nums[left];
}

int main() {	
	
	vector<int> nums = {3, 4, 5, 6, 1, 2};

	cout << findMin(nums) << endl;

	// Looks to where it is not sorted!!
	// Check if the final element is greater than the middle element
	// If it is, then everything is sorted and we can check the other
	// part
	//
	return 0;
}
