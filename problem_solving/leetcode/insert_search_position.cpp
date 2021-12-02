#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target) {

	if (nums.size() == 0) {
		return 0;
	}

	int left = 0;
	int right = nums.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] == target) {
			return mid;
		} else if (nums[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return left;
}

int main() {

	vector<int> nums = {1, 3, 5, 6};
	vector<int> targets = {5, 2, 7};

	for (int i = 0; i < targets.size(); i++) {
		cout << "Output -> " << searchInsert(nums, targets[i]) << endl;
	}

	/*
	 * Problem
	 *
	 * 	Given a sorted array of distinct integers and a target value, return the
	 * 	index if the target is found. If not, return the index where it would be
	 * 	if it were inserted in order.
	 *
	 * 	You must write an algorithm with O(log n) runtime complexity.
	 *
	 * 	Examples:
	 *
	 * 		Input = {1, 3, 5, 6}
	 * 		Target = 5
	 * 		Output = 2
	 *
	 * 		Input = {1, 3, 5, 6}
	 * 		Target = 2
	 * 		Output = 1
	 *
	 * 		Input = {1, 3, 5, 6}
	 * 		Target = 7
	 * 		Output = 4
	 *
	 * */	

	return 0;
}
