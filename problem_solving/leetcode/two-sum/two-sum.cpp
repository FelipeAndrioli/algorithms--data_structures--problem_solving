#include <iostream>
#include <vector>
#include <map>

class Solution {
	public:
	
		void showArray(std::vector<int>& nums) {
			for(int i = 0; i < nums.size(); i++) {
				std::cout << nums[i];
				std:: cout << " ";
			}
			std::cout << std::endl;
		}

		std::vector<int> twoSumOptimized(std::vector<int>& nums, int target) {
			//O(n) solution
			std::map<int, int> umap;
			int difference;

			for(int i = 0; i < nums.size(); i++) {
				difference = target - nums.at(i);

				if(umap.find(difference) != umap.end()) {
					std::vector<int> v{umap[difference], i};
					return v;
				} else {
					umap[nums.at(i)] = i;
				}
			}

			return std::vector<int> {};
		}

		std::vector<int> twoSum(std::vector<int>& nums, int target) {
			//O(n^2) solution
			std::vector<int> result;

			for(int i = 0; i < nums.size(); i++) {
				for(int j = 0; j < nums.size(); j++) {
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
	
	std::vector<int> nums = {2, 7, 11, 15};
	int target = 9;

	Solution solution;
	//std::vector<int> targetIndex = solution.twoSum(nums, target);
	std::vector<int> targetIndex = solution.twoSumOptimized(nums, target);
	solution.showArray(targetIndex);

	return 0;
}
