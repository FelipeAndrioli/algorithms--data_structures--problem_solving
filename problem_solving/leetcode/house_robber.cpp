#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int rob(vector<int> nums) {

    int ns = nums.size();

    if (ns == 1) {
        return nums[0];
    } 

    int possible_house_2 = nums[0];
    int possible_house = max(nums[0], nums[1]);
    int current_house = possible_house;

    for (int i = 2; i < ns; i++) {
        current_house = max(possible_house, possible_house_2 + nums[i]);
        possible_house_2 = possible_house;
        possible_house = current_house;
    }

    return current_house;
}

int main() {

    //vector<int> money = {2, 7, 9, 3, 1};
    //vector<int> money = {1, 2, 3, 1};
    vector<int> money = {2, 1, 1, 2};

    cout << rob(money) << endl; 

    return 0;
}