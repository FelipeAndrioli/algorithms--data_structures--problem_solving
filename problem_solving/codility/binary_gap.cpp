#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> decimalToBinary(int N) {
	vector<int> binary;

	while (N > 0) {
		binary.push_back(N % 2);
		N = N / 2;
	}
	
	reverse(binary.begin(), binary.end());

	return binary;
}

int binaryGap(int N) {

	vector<int> binary = decimalToBinary(N);

	int gap = 0;
	int temp_gap = 0;

	for (int i = 0; i < binary.size(); i++) {
		if (binary[i] == 0) {
			temp_gap++;	
		} else if (binary[i] == 0 && i == binary.size() - 1) {
			temp_gap++;
			if (temp_gap > gap) {
				gap = temp_gap;
			}
		} else if (binary[i] == 1) {
			if (temp_gap > gap) {
				gap = temp_gap;
			}

			temp_gap = 0;
		}
	}

	return gap;
}

int main() {

	int N;
	cin >> N;
	cout << "-> " << binaryGap(N) << endl;

	return 0;
}
