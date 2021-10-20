#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int solution(vector<int> &A) {

	if (A.size() == 0) {
		return 1;
	}

	sort(A.begin(), A.end());
	
	if (A[0] != 1) {
		return 1;
	}

	for (int i = 0; i < A.size(); i++) {
		if (A[i + 1] != A[i] + 1) {
			return A[i] + 1;
		}	
	}

	return A[A.size() - 1] + 1;
}

int main() {

	vector<int> A = {2, 1, 3, 5, 6, 7, 4};

	cout << solution(A) << endl;

	/*
	 * 	Problem
	 *
	 *	An array A consisting of N different integers is given. The array contains integers in the range 
	 *	[1..(N + 1)], which means that exactly one element is missing.

		Your goal is to find that missing element.

		Write a function:

		int solution(int A[], int N);

		that, given an array A, returns the value of the missing element.

		For example, given array A such that:

		  A[0] = 2
		  A[1] = 3
		  A[2] = 1
		  A[3] = 5
		the function should return 4, as it is the missing element.

		Write an efficient algorithm for the following assumptions:

		N is an integer within the range [0..100,000];
		the elements of A are all distinct;
		each element of array A is an integer within the range [1..(N + 1)].

		Solution
		
		My first solution was already a optimized one, sorting the given array and looping through it only once.
		Before start the loop we check if the first element is different from 1, then it is returned. Inside the
		loop we check if the next element is different from the current element + 1, if it is different, then we
		return the current element + 1, otherwise the array is complete and we need to return the last element + 1.

		Complexity

		Once we're using an native method to sort the array it wont affect the complexity, which in the case is O(n).
		If we're going to implement an function to sort the array it would have an complexity of O(log(n)) and then
		added with our O(n) needed to check the elements we finish with O(n * log(n)).
	 * */

	return 0;
}
