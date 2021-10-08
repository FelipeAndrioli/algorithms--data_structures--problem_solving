#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        int goodNodes(TreeNode* root);
        int recursiveSolution(TreeNode* root, int max_value);
};

int Solution::recursiveSolution(TreeNode* root, int max_value) {
    if (root == NULL) {
        return 0;
    }

    int answer = 0;

    if ((root->val) >= max_value) {
        answer++;
    }

    max_value = max(max_value, root->val);

    return answer + recursiveSolution(root->right, max_value) + recursiveSolution(root->left, max_value);
}

int Solution::goodNodes(TreeNode* root) {
    return recursiveSolution(root, root->val);
}

int main() {

    Solution solution;

    return 0;
}