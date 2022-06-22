// Given two Binary Trees A and B, you need to merge them in a single binary tree.

// The merge rule is that if two nodes overlap, then sum of node values is the new value of the merged node.

// Otherwise, the non-null node will be used as the node of new tree.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

TreeNode* Solution::solve(TreeNode* root1, TreeNode* root2) {
    if(root1 != NULL && root2 != NULL){
        root1->val += root2->val;
        root1->left = solve(root1->left, root2->left);
        root1->right = solve(root1->right, root2->right);
    }else if(root1){
        return root1;
    }else if(root2){
        return root2;
    }
    return root1;
}
