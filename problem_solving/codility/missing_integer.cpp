#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
	
	set<int> N;
	set<int>::iterator it;

	for (int i = 0; i < A.size(); i++) {
		N.insert(A[i]);
	}

	int sequence = 0;

	for (it = N.begin(); it != N.end(); it++) {
		if (*it != sequence + 1 && *it > 0) {
			return sequence + 1;
		} else if (*it > 0) {
			sequence++;
		}
	}

	return sequence + 1;
}

int main() {

//	vector<int> A = {1, 3, 6, 4, 1, 2};

	vector<int> A = {-2 ,-4};
	cout << solution(A) << endl;

	/*
	 * Problem
	 *	
	 *	This is a demo task.

		Write a function:

		int solution(vector<int> &A);

		that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

		For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

		Given A = [1, 2, 3], the function should return 4.

		Given A = [¿1, ¿3], the function should return 1.

		Write an efficient algorithm for the following assumptions:

		N is an integer within the range [1..100,000];
		each element of array A is an integer within the range [¿1,000,000..1,000,000].
	 
	 * Solution
	 *	
	 *	My initial solution was already the optimized one, once I already solve this challenge. I tried to improve it 
	 *	anyway, so this time I decided to use an set instead of an array. Using a set we are going to have only unique and
	 *	sorted values. After that we can loop through the set and check the values, if the current value is different from 
	 *	the next number in sequence + 1 and positive, than we return the sequence + 1. Otherwise if the value is positive
	 *	we add one to the sequence. If the sequence is completed or there are only negative values inside the array we 
	 *	return sequence + 1, which is going to be 1 or the maximum value in the array + 1.
	 *
	 *
	 * Complexity
	 *
	 *	The complexity in this case can be measured in two ways, considering the sort or without considering the sort. 
	 *	Without consider the sort, we are going to have a O(n) complexity, once we loop through the array once and through
	 *	the set once. Considering the sort we need to consider the sort complexity wich is O(n * log n), and then loop through
	 *	the sorted set O(n). By the end we are goin to have O(2 * n * log n), resulting in O(n * log n).
	 *
	 * */

	return 0;
}
