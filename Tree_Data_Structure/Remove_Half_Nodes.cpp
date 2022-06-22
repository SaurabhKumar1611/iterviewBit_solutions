// Given a binary tree A with N nodes.

// You have to remove all the half nodes and return the final binary tree.

// NOTE:

// Half nodes are nodes which have only one child.
// Leaves should not be touched as they have both children as NULL.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* root) {
	if(root == NULL){
		return NULL;
	}
	if(root->left && root->right){
		root->left = solve(root->left);
		root->right = solve(root->right);
	}else if(root->left){
		return solve(root->left);
	}else if(root->right){
		return solve(root->right);
	}
    return root;
}
