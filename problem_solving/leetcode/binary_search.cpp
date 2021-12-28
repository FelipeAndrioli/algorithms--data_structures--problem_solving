#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int recursiveBinarySearch(vector<int>& nums, int target, int left, int right) {
	int mid = left + (right - left) / 2;
	int search_result = -1;

	if (nums[mid] == target) {
		return mid;
	}

	if (nums[mid + 1] <= target) {
		search_result = recursiveBinarySearch(nums, target, mid + 1, right);
	} else if (nums[mid - 1] >= target) {
		search_result = recursiveBinarySearch(nums, target, left, mid - 1);
	}

	return search_result;
}

int search(vector<int>& nums, int target) {	
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

	if (target > nums[nums.size() -1] || target < nums[0]) {
		return -1;
	}

	return recursiveBinarySearch(nums, target, 0, nums.size() - 1);
}

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

	vector<int> nums = {-1,0,3,5,9,12};
	int target = 13; 

	cout << "Binary search...." << endl;
	//cout << nonRecursiveBinarySearch(nums, target) << endl;
	cout << search(nums, target) << endl;

	return 0;
}
