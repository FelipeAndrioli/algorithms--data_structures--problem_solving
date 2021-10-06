#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution{ 
    public:
        int minDeletions(string s);
};

int Solution::minDeletions(string s) {

    int deletions = 0;

    //Need to count letters
    unordered_map<char, int> letters;

    //store a letter and its frequency
    for (int i = 0; i < s.length(); i++) {
        letters[s[i]]++;
    } 

    //Need to iterate through our map
    unordered_map<char, int>::iterator it;

    //Ideal frequency
    unordered_set<int> frequency;

    //Loop through letters/frequency mamp
    for (it = letters.begin(); it != letters.end(); it++) {
        //Once the frequency is bigger than 0 and counts inside ideal frequency, it enters the loop
        while (it->second > 0 && (frequency.count(it->second))) {
            //If enters the loop then it needs to add one deletion and remove one from the frequency inside the map
            deletions++;
            it->second--;

            //Chech again to see if need to delete once again
        }

        //Add the value inside the ideal frequency
        frequency.insert(it->second);
    }

    //Return the number of deletions but can also return the ideal string, once we keep track of it inside the map

    return deletions;
}

int main() {

    Solution solution;
    string s = "aab";
    string s2 = "aaabbbcc";
    string s3 = "ceabaacb";

    int minimum_deletions = 0;

    minimum_deletions = solution.minDeletions(s);

    if (minimum_deletions == 0) {
        cout << "0 - Test 1 Passed" << endl;
    } else {
        cout << minimum_deletions << " - Test 1 Failed" << endl;
    }
    
    minimum_deletions = solution.minDeletions(s2);

    if (minimum_deletions == 2) {
        cout << "2 - Test 2 Passed" << endl;
    } else {
        cout << minimum_deletions << " - Test 2 Failed" << endl;
    }

    minimum_deletions = solution.minDeletions(s3);

    if (minimum_deletions == 2) {
        cout << "2 - Test 3 Passed" << endl;
    } else {
        cout << minimum_deletions << " - Test 3 Failed" << endl;
    }

    return 0;
}