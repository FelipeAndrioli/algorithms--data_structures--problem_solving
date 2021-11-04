#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(int A, int B, int C) {
	if (A % C == 0) {
		return (B / C - A / C + 1);
	}

	return (B / C - A / C);
}

int main() {

	cout << solution(6, 11, 2) << endl;	
	cout << solution(11, 345, 17) << endl;	
	cout << solution(0, 0, 11) << endl;	
	cout << solution(1, 1, 11) << endl;
	cout << solution(100, 123000000, 2) << endl;

	/*
	 * Problem
	 *
	 *	Write a function:

		int solution(int A, int B, int K);

		that, given three integers A, B and K, returns the number of integers within the range [A..B] that are 
		divisible by K, i.e.:

		{ i : A <= i <= B, i mod K = 0 }

		For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers 
		divisible by 2 within the range [6..11], namely 6, 8 and 10.

		Write an efficient algorithm for the following assumptions:

		A and B are integers within the range [0..2,000,000,000];
		K is an integer within the range [1..2,000,000,000];
		A <= B.
	 *
	 * Solution
	 * 	
	 * 	My first solution was to loop from A to B, checking each value of it if it is divisable from C, it wasn't 
	 * 	optimized.
	 *	
	 *	I wasn't able to reach a optimized solution, so I had to look for it. The one I find is pretty much similar
	 *	to what I've been doing. It checks if the A is divisible for C, and if it is, it returns the subtraction of
	 *	A and B divided by C plus 1 which results in the number of possible divisions. If A is not divisible for C then
	 *	we return the subtraction of A and B divided by C.
	 *
	 * Complexity
	 *	
	 *	The first solution have a complexity of O(B - A).
	 *
	 * 	The optimized solution have a complexity of O(1).
	 * */	

	return 0;
}
