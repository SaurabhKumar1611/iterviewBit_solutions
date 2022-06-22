// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
// Return 0 / 1 ( 0 for false, 1 for true ).

// Input 1:

//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
// Input 2:

//     1
//    / \
//   2   2
//    \   \
//    3    3

// Output 1:

//  1
// Output 2:

//  0

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int solve(TreeNode *leftTree, TreeNode *rightTree){
    if(leftTree && rightTree && leftTree->val == rightTree->val){
        if(solve(leftTree->left, rightTree->right) && solve(leftTree->right, rightTree->left)){
            return 1;
        }
    }else if(!leftTree && !rightTree){
        return 1;
    }
    return 0;
}
    
int Solution::isSymmetric(TreeNode* root) {
    if(root == NULL){
        return 1;
    }else{
        return solve(root->left, root->right);
    }
}
