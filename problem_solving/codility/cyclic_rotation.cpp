#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
	int rotations = 0;

	if (A.size() == 0) {
		return A;
	}
	
	int array_size = A.size() - 1;

	while (rotations < K) {
		int last_element = A[array_size];

		for (int i = array_size - 1; i >= 0; i--) {
			A[i + 1] = A[i];

			if (i == 0) {
				A[i] = last_element;
			}
		}

		rotations++;
	}

	return A;
}

int main() {

	//vector<int>original_array = {3, 8, 9, 7, 6};
	//int rotations = 3;
	
	//vector<int>original_array = {0, 0, 0};
	//int rotations = 1;

	vector<int>array = {};
	int rotations = 3;

	array = solution(array, rotations);

	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}

	cout << endl;

	/*
	 * Problem
	 	An array A consisting of N integers is given. Rotation of the array means that each element is shifted right 
		by one index, and the last element of the array is moved to the first place. For example, the rotation of 
		array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the 
		first place).

		The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

		Write a function:

		class Solution { public int[] solution(int[] A, int K); }

		that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

		For example, given

		    A = [3, 8, 9, 7, 6]
		    K = 3
		the function should return [9, 7, 6, 3, 8]. Three rotations were made:

		    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
		    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
		    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
		For another example, given

		    A = [0, 0, 0]
		    K = 1
		the function should return [0, 0, 0]

		Given

		    A = [1, 2, 3, 4]
		    K = 4
		the function should return [1, 2, 3, 4]

		Assume that:

		N and K are integers within the range [0..100];
		each element of array A is an integer within the range [¿1,000..1,000].
	 *
	 * Solution
	 *	My solution was to keep track of the last element, once it need to change from last to first.
	 *	Then I started the loop in the last element - 1 and always change the next element to be equal
	 *	the current element. When we reach the first element we change its position and add the stored
	 *	last element to be the first.
	 *
	 *	It is not the best solution, a circular queue should be more efficient.
	 *
	 * Complexity
	 *	We need to iterate through the entire array with size N for K times, which result in a complexity
	 *	of O(n * k).
	 *
	 * */

	return 0;
}
