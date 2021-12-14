#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, int low, int high, int sum) {
        if (!root) {
            return 0;
        }
        
        int left = helper(root->left, low, high, sum);
        int right = helper(root->right, low, high, sum);
        
        if (root->val >= low && root->val <= high) {
            return sum + root->val + left + right;
        }
        
        return sum + left + right;
    }
    
int rangeSumBST(TreeNode* root, int low, int high) {       
    return helper(root, low, high, 0);
}

