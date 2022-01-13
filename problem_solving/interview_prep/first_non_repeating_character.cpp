#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void firstNonRepeatingCharacterOptimized(string s) {
	int fi[256];

	for (int i = 0; i < 256; i++) {
		fi[i] = -1;
	}

	for (int i = 0; i < s.size(); i++) {
		if (fi[s[i]] == -1) {
			fi[s[i]] = i;
		} else {
			fi[s[i]] = -2;
		}
	}

	for (int i = 0; i < 256; i++) {
		if (fi[s[i]] >= 0) {
			cout << "The first non repeating character is " << s[fi[s[i]]] << endl;
			return;
		}
	}
}

void firstNonRepeatingCharacter(string s) {
	unordered_map<char, int> my_map;
	unordered_map<char, int>::iterator it;

	for (int i = 0; i < s.size(); i++) {
		my_map[s[i]]++;
	}

	for (it = my_map.begin(); it != my_map.end(); it++) {
		if (it->second == 1) {
			cout << "The first non repeating character is " << it->first << endl;
			return;
		}
	}

	cout << "There isn't any non repeating character..." << endl;
}

int main() {

	string s = "abcdefedcb";

	firstNonRepeatingCharacterOptimized(s);
	
	return 0;
}
