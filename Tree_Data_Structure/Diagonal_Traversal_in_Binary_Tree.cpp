// Consider lines of slope -1 passing between nodes.

// Given a Binary Tree A containing N nodes, return all diagonal elements in a binary tree belonging to same line.

// NOTE:

// See Sample Explanation for better understanding.
// Order does matter in the output.
// To get the same order as in the output traverse the tree same as we do in pre-order traversal.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Recursive solution in O(n) time and space

// void diagonalTraversal(TreeNode *root, vector<vector<int> > &traversal, int depth = 0){
// 	if(root){
// 		if(traversal.size() <= depth){
// 			traversal.push_back(vector<int> {root->val});
// 		}else{
// 			traversal[depth].push_back(root->val);
// 		}
// 		diagonalTraversal(root->left, traversal, depth + 1);
// 		diagonalTraversal(root->right, traversal, depth);
// 	}
// }

// vector<int> Solution::solve(TreeNode* root) {
// 	vector<vector<int> > traversal;
// 	diagonalTraversal(root, traversal);
// 	vector<int> ans;
// 	for(int i = 0; i < traversal.size(); i++){
// 		for(int j = 0; j < traversal[i].size(); j++){
// 			ans.push_back(traversal[i][j]);
// 		}
// 	}
// 	return ans;
// }

// Iterative solution using queue in O(n) time and space

vector<int> Solution::solve(TreeNode* root) {
	vector<int> traversal;
	queue<TreeNode *> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *p = q.front();
		q.pop();
		while(p){
			if(p->left){
				q.push(p->left);
			}
            traversal.push_back(p->val);
			p = p->right;
		}
	}
	return traversal;
}
