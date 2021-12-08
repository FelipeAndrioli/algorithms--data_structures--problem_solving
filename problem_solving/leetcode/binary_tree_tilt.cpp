#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int totalTilt = 0;

int valueSum(TreeNode* node) {
	if (!node) {
		return 0;
	}

	int leftSum = valueSum(node->left);
	int rightSum = valueSum(node->right);
	int tilt = abs(leftSum - rightSum);
	totalTilt += tilt;

	return node->val + leftSum + rightSum;
}

int findTilt(TreeNode *root) {
	valueSum(root);

	return totalTilt;
}
