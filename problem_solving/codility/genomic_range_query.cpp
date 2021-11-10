#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> optimizedSolution(string &S, vector<int> &P, vector<int> &Q) {
	vector<int> queries_answer;
	int string_size = S.size();
	int occurrences[string_size][4];
	
	fill(*occurrences, *occurrences + string_size * 4, 0);

	for (int i = 0; i < string_size; i++) {
		if (S[i] == 'A') {
			occurrences[i][0] = 1;
		} else if (S[i] == 'C') {
			occurrences[i][1] = 1;
		} else if (S[i] == 'G') {
			occurrences[i][2] = 1;
		} else if (S[i] == 'T') {
			occurrences[i][3] = 1;
		}
	}

	for (int i = 1; i < string_size; i++) {
		for (int j = 0; j < 4; j++) {
			occurrences[i][j] += occurrences[i - 1][j];
		}
	}

	for (int i = 0; i < P.size(); i++) {
		int start_range = P[i];
		int end_range = Q[i];

		for (int j = 0; j < 4; j++) {
			int sub = 0;

			if (start_range - 1 >= 0) {
				sub = occurrences[start_range - 1][j];
			}

			if (occurrences[end_range][j] - sub > 0) {
				queries_answer.push_back(j + 1);
				break;
			}
		}
	}

	return queries_answer;
}

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
	
	//I'm going to use the index to get the impact factor from each letter
	vector<char> impact_factor = {'A', 'C', 'G', 'T'};

	vector<int> queries_answer;

	int arrays_size = P.size();

	for (int i = 0; i < arrays_size; i++) {
		int starting_range = P[i];
		int ending_range = Q[i];
		int min_impact = 0;

		vector<int> temp;

		for (int j = starting_range; j <= ending_range; j++) {
			for (int k = 0; k < impact_factor.size(); k++) {
				if (S[j] == impact_factor[k]) {
					temp.push_back(k + 1);
				}
			}
		}
	
		min_impact = temp[0];

		for (int k = 1; k < temp.size(); k++) {
			if (temp[k] < min_impact) {
				min_impact = temp[k];
			}
		}

		queries_answer.push_back(min_impact);
	}
	
	return queries_answer;
}

vector<int> mapSolution(string &S, vector<int> &P, vector<int> &Q) {
	unordered_map<char, int> impact_factor;
	unordered_map<char, int>::iterator it;

	impact_factor['A'] = 1;
	impact_factor['C'] = 2;
	impact_factor['G'] = 3;
	impact_factor['T'] = 4;

	vector<int> queries_answer;

	int arrays_size = P.size();

	for (int i = 0; i < arrays_size; i++) {
		auto start_range = S.begin() + P[i];
		auto end_range = S.begin() + 1 + Q[i];

		unordered_set<char> dna(start_range, end_range);
		
		int query_answer = INT_MAX;

		for (it = impact_factor.begin(); it != impact_factor.end(); it++) {
			if (dna.find(it->first) != dna.end()) {
				query_answer = min(it->second, query_answer);
			}
		}

		queries_answer.push_back(query_answer);
	}
		
	return queries_answer;
}

int main() {

	vector<int> P = {2, 5, 0};
	vector<int> Q = {4, 5, 6};
	string S = "CAGCCTA";

	//vector<int> P = {0, 0, 1};
	//vector<int> Q = {0, 1, 1};
	//string S = "AC";

	vector<int> queries = optimizedSolution(S, P, Q);
	
	for (int i = 0; i < queries.size(); i++) {
		cout << queries[i] << " ";
	}

	cout << endl;

	/*
	 * Problem
	 *	A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which 
	 *	correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact 
	 *	factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 
	 *	and 4, respectively. You are going to answer several queries of the form: What is the minimal impact 
	 *	factor of nucleotides contained in a particular part of the given DNA sequence?

		The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There 
		are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th 
		query (0 <= K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence 
		between positions P[K] and Q[K] (inclusive).

		For example, consider string S = CAGCCTA and arrays P, Q such that:

		    P[0] = 2    Q[0] = 4
		    P[1] = 5    Q[1] = 5
		    P[2] = 0    Q[2] = 6
		
		The answers to these M = 3 queries are as follows:

		The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors 
		are 3 and 2 respectively, so the answer is 2.
		The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
		The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose 
		impact factor is 1, so the answer is 1.
		
		Write a function:

		vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

		that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M 
		integers, returns an array consisting of M integers specifying the consecutive answers to all queries.

		Result array should be returned as a vector of integers.

		For example, given the string S = CAGCCTA and arrays P, Q such that:

		    P[0] = 2    Q[0] = 4
		    P[1] = 5    Q[1] = 5
		    P[2] = 0    Q[2] = 6
		
		the function should return the values [2, 4, 1], as explained above.

		Write an efficient algorithm for the following assumptions:

		N is an integer within the range [1..100,000];
		M is an integer within the range [1..50,000];
		each element of arrays P and Q is an integer within the range [0..N - 1];
		P[K] <= Q[K], where 0 <= K < M;
		string S consists only of upper-case English letters A, C, G, T.

	 * Solution
	 * 
	 *	The initial solution was to loop through the received query arrays getting the starting and ending range values. Then
	 *	we loop through the DNA received string with the new ranges created values. After that we need to loop through each value
	 *	from the impact factor comparing to the current DNA value and add its impact to a temporary array. The final step is to 
	 *	loop through the temp array and get the minimum value.
	 *
	 * Complexity
	 *
	 * 	The time complexity is O(n * m), being n the received queries array size, m being the range created by the
	 * 	received querie arrays. Despite having some more loops inside m, they are going to be constants, so we don't
	 * 	need to count them in the complexity.
	 * 	 
	 * 	
	 */

	return 0;
}
