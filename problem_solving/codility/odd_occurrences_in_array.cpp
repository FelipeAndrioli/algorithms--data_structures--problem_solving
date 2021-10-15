#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
	int unpaired_element = 0;

	unordered_map<int, int>elements;
	unordered_map<int, int>::iterator it;

	for (int i = 0; i < A.size(); i++) {
		elements[A[i]]++;
	}

	for (it = elements.begin(); it != elements.end(); it++) {
		if (it->second % 2 == 1) {
			unpaired_element = it->first;
		}
	}

	return unpaired_element;
}

int main() {
	
	vector<int> A = {9, 3, 9, 3, 9, 7, 9};
	int unpaired_element = solution(A);

	cout << unpaired_element << endl;

	/*	Problem
	 *
	 *	A non-empty array A consisting of N integers is given. The array contains an odd number of elements, 
	 *	and each element of the array can be paired with another element that has the same value, except for one 
	 *	element that is left unpaired.

		For example, in array A such that:

			A[0] = 9  A[1] = 3  A[2] = 9
			A[3] = 3  A[4] = 9  A[5] = 7
			A[6] = 9

		the elements at indexes 0 and 2 have value 9,
		the elements at indexes 1 and 3 have value 3,
		the elements at indexes 4 and 6 have value 9,
		the element at index 5 has value 7 and is unpaired.
		Write a function:

		int solution(vector<int> &A);

		that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

		For example, given array A such that:

			A[0] = 9  A[1] = 3  A[2] = 9
			A[3] = 3  A[4] = 9  A[5] = 7
			A[6] = 9

		Solution
		
		The solution I found, was to loop through the entire array adding the values into a unordered map, once
		the values will not repeat and will only count its appearences. Then we need to loop through the map to
		check each element an see if it is even or odd. If it is odd, then it is the unpaired element.

		Complexity

		The complexity to loop through the array is O(n), and the complexity to loop through the map in the worst
		case is O(1 + n / 2), in Big O notation we can remove the constants so it becames O(n). 
	
		Adding the two complexities we are going to have O(2 * n) -> O(n).
	 * */

	return 0;
}
