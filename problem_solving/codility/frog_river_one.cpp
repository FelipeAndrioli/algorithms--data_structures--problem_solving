#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int solution(int X, vector<int> &A) {

	map<int, int> L;
	map<int, int>::iterator it;

	for (int i = 0; i < A.size(); i++) {
		if (L.find(A[i]) == L.end()) {
			L[A[i]] = i;
		}
	}

	int check = 0;
	int second = 0;

	for (it = L.begin(); it != L.end(); it++) {
		if (it->first == check + 1) {
			check = it->first;

			if (it->second > second) {
				second = it->second;
			}
		} else {
			break;
		}

		if (check == X) {
			return second;
		}
	}

	return -1;
}

int main() {
	
	int X = 5;
	vector <int> A = {1, 3, 1, 4, 2, 3, 5, 4};

	vector <int> A = {2};

	cout << solution(X, A) << endl;
/*
 *	A small frog wants to get to the other side of a river. The frog is initially located on one bank of the 
 *	river (position 0) and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.

	You are given an array A consisting of N integers representing the falling leaves. A[K] represents the 
	position where one leaf falls at time K, measured in seconds.

	The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross 
	only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment 
	when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river 
	is negligibly small, i.e. the leaves do not change their positions once they fall in the river.

	For example, you are given integer X = 5 and array A such that:

		  A[0] = 1
		  A[1] = 3
		  A[2] = 1
		  A[3] = 4
		  A[4] = 2
		  A[5] = 3
		  A[6] = 5
		  A[7] = 4
	
	In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.

		Write a function:

		int solution(int X, vector<int> &A);

		that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog 
		can jump to the other side of the river.

		If the frog is never able to jump to the other side of the river, the function should return ?1.

		For example, given X = 5 and array A such that:

		  A[0] = 1
		  A[1] = 3
		  A[2] = 1
		  A[3] = 4
		  A[4] = 2
		  A[5] = 3
		  A[6] = 5
		  A[7] = 4
		the function should return 6, as explained above.

		Write an efficient algorithm for the following assumptions:

		N and X are integers within the range [1..100,000];
		each element of array A is an integer within the range [1..X].

	Solution:

		My initial solution was already the optimized one. It loop through the leafs and add the leaf and its second
		into a map, then we loop through the map to check if the order is correct and get the second which the last
		leaf falls, and then we return this second.

	Complexity:

		The complexity of this solution is O(n), once it loops through the array once O(n) and loop through the map
		once O(n). Which results in a complexity of O(2 * n), as in big O notation ignores the constants it results
		in O(n).
 *
 * */

	return 0;
}
