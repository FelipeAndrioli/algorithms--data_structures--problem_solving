#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longestSubstringWithKDifferentCharacters(string s, int k) {
	int start = 0;
	int longest = -1;

	unordered_map<char, int> my_map;

	for (int i = 0; i < s.size(); i++) {
		my_map[s[i]]++;

		if (my_map.size() == k) {
			longest = max(longest, i - start + 1);
		}

		if (my_map.size() > k) {
			while (my_map.size() > k) {
				my_map[s[start]]--;
				
				if (my_map[s[start]] == 0) {
					my_map.erase(s[start]);
				}
				start++;
			}
		}
	}

	return longest;
}

int main() {

	string s = "aabbcc";
	int k = 1;

	cout << longestSubstringWithKDifferentCharacters(s, k) << endl;

	return 0;
}
