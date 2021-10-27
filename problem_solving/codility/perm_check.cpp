#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {

	map<int, int> N;
	map<int, int>::iterator it;

	for (int i = 0; i < A.size(); i++) {
		N[A[i]]++;	
	}
	
	int check = 0; 

	for (it = N.begin(); it != N.end(); it++) {
		if (it->first != check + 1 || it->second != 1) {
			return 0;
		}

		check = it->first;
	}

	return 1;
}

int main() {

	vector<int> A = {4, 1, 3, 2};
//	vector<int> A = {1, 1};

	cout << solution(A) << endl;

/*
 *	Problem:
 *
 * 	A non-empty array A consisting of N integers is given.

	A permutation is a sequence containing each element from 1 to N once, and only once.

	For example, array A such that:

	    A[0] = 4
	    A[1] = 1
	    A[2] = 3
	    A[3] = 2
	is a permutation, but array A such that:

	    A[0] = 4
	    A[1] = 1
	    A[2] = 3
	is not a permutation, because value 2 is missing.

	The goal is to check whether array A is a permutation.

	Write a function:

	int solution(vector<int> &A);

	that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

	For example, given array A such that:

	    A[0] = 4
	    A[1] = 1
	    A[2] = 3
	    A[3] = 2
	the function should return 1.

	Given array A such that:

	    A[0] = 4
	    A[1] = 1
	    A[2] = 3
	the function should return 0.

	Write an efficient algorithm for the following assumptions:

	N is an integer within the range [1..100,000];
	each element of array A is an integer within the range [1..1,000,000,000].

	Solution:
	
	My first solution was already the optimized one. We need to loop through the entire array once and add each
	element to a map, with its occurrencies. Then we need to loop through the map verifying if the sequence is
	correct and if the value is not occurring more than one time.

	Complexity:

	Doing it with C++ libraries we got a O(n) complexity, once we need to loop through the array once and through the
	map once. But if we haven't the libraries we probably are going to need to order and count by ourselves. This would
	give us a time complexity of O(n * log n).
 * */

	return 0;
}
