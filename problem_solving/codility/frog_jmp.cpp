#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solution(int X, int Y, int D) {

	if (X >= Y) {
		return 0;
	}

	double jump = double(Y - X) / (double) D;

	return ceil(jump);
}

int main() {

	int X = 10;
	int Y = 85;
	int D = 30;

//	int X = 3;
//	int Y = 999111321;
//	int D = 7;

	//cin >> X >> Y >> D;

	cout << solution(X, Y, D) << endl;

	/*
	 * Problem
	 *
	 * 	A small frog wants to get to the other side of the road. The frog is currently located at position X 
	 * 	and wants to get to a position greater than or equal to Y. The small frog always jumps a fixed distance, D.

		Count the minimal number of jumps that the small frog must perform to reach its target.

		Write a function:

		int solution(int X, int Y, int D);

		that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal 
		to or greater than Y.

		For example, given:

		  X = 10
		  Y = 85
		  D = 30
		the function should return 3, because the frog will be positioned as follows:

		after the first jump, at position 10 + 30 = 40
		after the second jump, at position 10 + 30 + 30 = 70
		after the third jump, at position 10 + 30 + 30 + 30 = 100
		Write an efficient algorithm for the following assumptions:

		X, Y and D are integers within the range [1..1,000,000,000];
		X <= Y.

		
		Solution

			The initial solution was a bruteforce that add the D into X many times trying to reach the Y value. The
			solution wasn't efficient enough because in the worst case it had a very big complexity.

			The second and best solution was to subtract the X from the Y because Y is the total distance, and the
			X is the distance that we already went through, after that we are able to divide this result for the
			distance of each jump which will probably result into a not integer number, after that we just need to
			round up (or ceil) the number and we got our answer.

		Complexity

			The complexity of the initial solution in the worst case is O(n), n being the value of Y.

			The complexity of the second solution is O(1).
	 * */

	return 0;
}
