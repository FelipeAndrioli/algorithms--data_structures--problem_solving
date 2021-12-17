#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string reverse_string(string s) {
	string reversed_string = "";

	for (int i = s.length() - 1; i >= 0; i--) {
		reversed_string.push_back(s[i]);
	}
	return reversed_string;
}

int main() {

	string s = "nemaR";
	string r_s = reverse_string(s);

	cout << r_s << endl;

	return 0;
}
