#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
	sort(A.begin(), A.end());

	if(A[A.size() - 1] <= 0) {
		return 1;
	}

	bool is_one = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 1) {
			is_one = true;
		}
	}

	if (!is_one) {
		return 1;
	}

	for (int i = 0; i < A.size() - 1; i++) {
		if (A[i] > 0 && a[i + 1] - A[i] > 1) {
			return A[i] + 1;
		}
	}

	return A[A.size() - 1] + 1;
}

int main() {

	/*
	 * Problem:
	 * 	Given an array, find the smallest positive integer which is NOT in the array.
	 *
	 * Corner cases:
	 *	- Array is unordered
	 *	- Only negative values
	 *	- If there is no 1 in the array
	 *	- If the array is completely sequencial
	 *
	 * Solution:
	 * 	- First idea was to sort the array
	 * 	- After that we can chack the last element and see if it is negative, if it is we return 1
	 * 	- Then we gotta check if there is at least one 1, and if it's not, then we return 1
	 * 	- Finally we are going to check every element, if we found some which is bigger than 0, and if the
	 * 		next element after that has a gap bigger than 1, we return the current element + 1
	 * 	- In the end we gotta fix another corner case, in the case that the array is completely sequencial
	 * 		we return the last element + 1
	 *
	 * Complexity:
	 *
	 * 	- We run through the array two times, which give us O(2 * n), that can also be writted as O(n)
	 *
	 * */

	//should return 5
	vector<int> array = {1, 3, 6, 4, 1, 2};

	cout << solution(array) << endl;

	return 0;
}
