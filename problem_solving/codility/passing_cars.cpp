#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &A) {
	int cars = 0;
	int count = 0;

	for (int i = 0; i < A.size(); i++) {
		if (A[i] == 0) {
			count++;
		} else if (A[i] == 1) {
			cars += count;
		}
	}

	if (cars > 1000000000 || cars < 1000000000) {
		return -1;
	}

	return cars;
}

int main() {

	vector<int> A = {0, 1, 0, 1, 1};

	cout << solution(A) << endl;

	/*
	 * 	Problem
	 *
	 * 	A non-empty array A consisting of N integers is given. The consecutive elements of array 
	 * 	A represent consecutive cars on a road.

		Array A contains only 0s and/or 1s:

		0 represents a car traveling east,
		1 represents a car traveling west.
		The goal is to count passing cars. We say that a pair of cars (P, Q), where 0 <= P < Q < N, is passing 
		when P is traveling to the east and Q is traveling to the west.

		For example, consider array A such that:

		  A[0] = 0
		  A[1] = 1
		  A[2] = 0
		  A[3] = 1
		  A[4] = 1
		We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).

		Write a function:

		int solution(vector<int> &A);

		that, given a non-empty array A of N integers, returns the number of pairs of passing cars.

		The function should return -1 if the number of pairs of passing cars exceeds 1,000,000,000.

		For example, given:

		  A[0] = 0
		  A[1] = 1
		  A[2] = 0
		  A[3] = 1
		  A[4] = 1
		the function should return 5, as explained above.

		Write an efficient algorithm for the following assumptions:

		N is an integer within the range [1..100,000];
		each element of array A is an integer that can have one of the following values: 0, 1.
	 
		Solution
		
		My first solution was to loop through the array once, keep tracking of one car, and then loop again
		looking for cars going into the opposite direction.

		The second solution is to loop through the array once, when we got 0 then we need to add one to count,
		and when we got 1, then we need to add count to cars. By the end we just check the limits to return -1 when
		needed.

		Complexity

		The initial solution wasn't the optimized one, as we need to loop through the array once, and for each iteration we
		need to loop again, the time complexity is O(n^2).

		The second solution is optimized, once it just need to loop through the array once, counting the cars in 0 and adding
		them to the cars variable when we find a 1 car. So the time complexity is O(n).
	 * */

	return 0;
}
