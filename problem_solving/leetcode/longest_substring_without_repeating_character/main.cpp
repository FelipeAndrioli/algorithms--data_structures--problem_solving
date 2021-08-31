#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
    public:

        void showString(std::string s) {
            for (int i = 0; i < s.length(); i++) {
                std::cout << s[i] << " ";
            }
            std::cout << std::endl;
        }

        int lengthOfLongestSubstringMap(std::string s) {
            int start = 0;
            int result = 0;
            std::unordered_map<char, int> charMap;

            for (int i = 0; i < s.length(); i++) {
                if (charMap.find(s[i]) == charMap.end() || charMap[s[i]] < start) {
                    charMap[s[i]] = i;
                } else {
                    if (i - start > result) {
                        result = i - start;
                    }

                    start = charMap[s[i]] + 1;
                    charMap[s[i]] = i;
                }
            }

            if ((s.length() - start) > result) {
                result = s.length() - start;
            }

            return result;
        }

        int lengthOfLongestSubstring(std::string s) {
            int result = 0;
            int temp_result = 0;
            int repeat = 0;
            std::string sub_string;

            for (int i = 0; i < s.length(); i++) {
                sub_string.push_back(s[i]);
                temp_result = sub_string.length();
                repeat = 0;

                for (int j = i + 1; j < s.length(); j++) {
                    for (int k = 0; k < sub_string.length(); k++) {
                        if (s[j] == sub_string[k]) {
                            repeat = 1;
                        }
                    }                  

                    if (repeat == 1) {
                        break;
                    } else if (repeat == 0) {
                        sub_string.push_back(s[j]);
                        temp_result++;
                    }
                }

                if (temp_result > result) {
                    result = temp_result;
                }

                sub_string.clear();
            }

            return result;
        }
};

int main() {

    std::string test_cases[] = {"afellipe", "uqinntq", "dvdf", "au", "abc", "abcabcbb", "bbbbb", "", " ", "pwwkew", "bwf", "abcdefghijklmnopqrstuvwxyz"};
    int array_size = sizeof(test_cases) / sizeof(*test_cases);

    Solution solution;

    for (int i = 0; i < array_size; i++) {
        std::cout << test_cases[i] << " = ";
        std::cout << solution.lengthOfLongestSubstringMap(test_cases[i]) << std::endl;
    }

    return 0;
}