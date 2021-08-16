#include <iostream>
#include <vector>

class Solution {
	public:
	
		void showArray(std::vector<int>& nums) {
			for(int i = 0; i < nums.size(); i++) {
				std::cout << nums[i];
				std:: cout << " ";
			}
			std::cout << std::endl;
		}

		std::vector<int> twoSum(std::vector<int>& nums, int target) {
			std::vector<int> result;

			for(int i = 0; i < nums.size(); i++) {
				for(int j = 0; j < nums.size(); j++) {
					std::cout << i << " - " << nums[i] << " - " << j << " - " << nums[j] << std::endl;
					if(nums[i] + nums[j] == target && i != j) {
						result.push_back(i);
						result.push_back(j);

						return result;
					}
				}
			}

			return result;
		}
};

int main() {
	
	std::vector<int> nums = {3, 3};
	int target = 6;

	Solution solution;
	std::vector<int> targetIndex = solution.twoSum(nums, target);
	solution.showArray(targetIndex);

	return 0;
}
