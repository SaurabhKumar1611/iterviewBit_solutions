// Given a binary tree, determine if it is height-balanced.

// Height-balanced binary tree  : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

// Return 0 / 1 ( 0 for false, 1 for true ) for this problem

// Example :

// Input : 
//           1
//          / \
//         2   3

// Return : True or 1 

// Input 2 : 
//          3
//         /
//        2
//       /
//      1

// Return : False or 0 
//          Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
//          Difference = 2 > 1. 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int height(TreeNode *root){
    if(!root){
        return 0;
    }
    int x = height(root->left);
    int y = height(root->right);
    if(x < 0 || y < 0){
        return -1;
    }else if(abs(x - y) <= 1){
        return 1 + max(x, y);
    }else{
        return -1;
    }
}
    
int Solution::isBalanced(TreeNode* root) {
    if(height(root) == -1){
        return 0;
    }else{
        return 1;
    }
}

// Bottom Up approach
// Time Complexity :- O(N)
