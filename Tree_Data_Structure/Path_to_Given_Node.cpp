// Given a Binary Tree A containing N nodes.

// You need to find the path from Root to a given node B.

// NOTE:

// No two nodes in the tree have same data values.
// You can assume that B is present in the tree A and a path always exists.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool preorder(TreeNode *root, vector<int> &path, int target){
	if(root == NULL){
		return 0;
	}
	path.push_back(root->val);
	if(root->val == target){
		return 1;
	}
	if(preorder(root->left, path, target) || preorder(root->right, path, target)){
		return 1;
	}
	path.pop_back();
	return 0;
}

vector<int> Solution::solve(TreeNode* root, int k) {
	vector<int> path;
	preorder(root, path, k);
	return path;
}
