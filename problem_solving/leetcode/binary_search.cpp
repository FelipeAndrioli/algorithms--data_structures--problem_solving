#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nonRecursiveBinarySearch(vector<int>& nums, int target) {

	if (nums.size() == 0) {
		return -1;
	} else if (nums.size() == 1) {
		if (nums[0] == target) {
			return 0;
		} else {
			return -1;
		}
	} else if (nums.size() == 2) {
		if (nums[0] == target) {
			return 0;
		} else if (nums[1] == target) {
			return 1;
		} else {
			return -1;
		}
	}

	int left = 0;
	int right = nums.size() - 1;

	while (left <= right) {
		int middle = left + (right - left) / 2;	

		if (nums[middle] == target) {
			return middle;
		}

		if (nums[middle + 1] <= target) {
			left = middle + 1;	
		} else if (nums[middle - 1] >= target) {
			right = middle - 1;
		} else {
			return -1;
		} 
	}

	return -1;
}

int main() {

	vector<int> nums = {2, 5};
	int target = 0; 

	cout << "Binary search...." << endl;
	cout << nonRecursiveBinarySearch(nums, target) << endl;

	return 0;
}
