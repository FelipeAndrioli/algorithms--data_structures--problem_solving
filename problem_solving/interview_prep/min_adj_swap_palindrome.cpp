#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minimumAdjacentSwaps(string s) {
    int string_size = s.length();
    int swap_count = 0;

    for (int i = 0; i < string_size / 2; i++) {
        int left = i;
        int right = string_size - i - 1;
        int count_badness = 0;

        while (left < right) {
            if (s[left] == s[right]) {
                break;
            } else {
                right--;
            }
        }

        if (right == left) {
            return -1;
        }

        for (int j = right; j < string_size - left - 1; j++) {
            swap(s[j], s[j + 1]);
            swap_count++;
        }
    }

    return swap_count;
}

int main() {

    /*
        Given a string, what is the minimum number of adjacent swaps required to convert a string 
        into a palindrome. If not possible, return -1

        The main algorithm have a problem, it just process the string from right to left, so if some mid letter
        is in the left part of the string it'll give a wrong answer, to solve this in the most quickly way I just 
        run it twice, reverting the string and taking the greater result
    */

    int minimum_swaps = 0;
    
    string s = "ntiin";
    string s_reverse = s;
    
    reverse(s_reverse.begin(), s_reverse.end());

    minimum_swaps = max(minimumAdjacentSwaps(s), minimumAdjacentSwaps(s_reverse));

    cout << minimumAdjacentSwaps(s) << endl;
    cout << minimumAdjacentSwaps(s_reverse) << endl;

    cout << minimum_swaps << endl;

    return 0;
}