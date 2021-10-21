#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <climits>

using namespace std;

int solution(vector<int> &A) {
	int minimum_difference = INT_MAX;
	int total_sum = 0;
	int left = 0;
	int right = 0;

	for (int i = 0; i < A.size(); i++) {
		total_sum += A[i];
	}

	for (int i = 0; i < A.size() - 1; i++) {
		left += A[i];
		right = total_sum - left;
		
		int temp_min = left - right;

		temp_min = abs(temp_min);

		if (temp_min < minimum_difference) {
			minimum_difference = temp_min;
		}
	}

	return minimum_difference;
}

int main() {

	//vector<int> A = {3, 1, 2, 4, 3};
	
	//vector<int> A = {-1000, 1000};

	//vector<int> A = {1, 1, 3};
	
	//vector<int> A = {2, 4, 6, 8};

	vector<int> A = {-2, -3, -4, -1};

	cout << solution(A) << endl;

	/*
	 * 	Problem
	 *
	 * 	A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

		Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P - 1] 
		and A[P], A[P + 1], ..., A[N - 1].

		The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P - 1]) - (A[P] + A[P + 1] + ... + 
		A[N - 1])|

		In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

		For example, consider array A such that:

		  A[0] = 3
		  A[1] = 1
		  A[2] = 2
		  A[3] = 4
		  A[4] = 3
		We can split this tape in four places:

		P = 1, difference = |3 - 10| = 7
		P = 2, difference = |4 - 9| = 5
		P = 3, difference = |6 - 7| = 1
		P = 4, difference = |10 - 3| = 7
		Write a function:

		int solution(vector<int> &A);

		that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

		For example, given:

		  A[0] = 3
		  A[1] = 1
		  A[2] = 2
		  A[3] = 4
		  A[4] = 3
		the function should return 1, as explained above.

		Write an efficient algorithm for the following assumptions:

		N is an integer within the range [2..100,000];
		each element of array A is an integer within the range [-1,000..1,000].

		Solution
		
		My first solution was to bruteforce the entire array and for each value we need to loop through the entire
		array once again, when the iteration of the second loop is smaller or equal the first loop, then we add
		the array value in left, else we add in right. The following steps are take the absolute difference and compare
		with the previous value we have.

		The second solution was to loop once through the entire array summing each value. After that we iterate again
		through the array keeping track of left part of the array, adding the current value to the left var. The
		right part of the array we calculate subtracting the left from the total value.

		Complexity

		My first solution wasn't very good, once it need to iterate through the array for each array value resulting
		in a complexity of O(n^2).

		The second solution loop once through the entire array O(n) to sum all the elements. And then loop the second
		time to calculate the difference O(n). In the end we are going to have O(2 * n) which is transformed in O(n).

	 * */

	return 0;
}
