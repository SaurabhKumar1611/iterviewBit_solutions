// Given a binary search tree, write a function to find the kth smallest element in the tree.

// Example :

// Input : 
//   2
//  / \
// 1   3

// and k = 2

// Return : 2

// As 2 is the second smallest element in the tree.
// NOTE : You may assume 1 <= k <= Total number of nodes in BST

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::kthsmallest(TreeNode* root, int k) {
    stack<TreeNode*> st;
    while(k){
        if(root){
            st.push(root);
            root = root->left;
        }else{
            k--;
            if(!k){
                break;
            }
            root = st.top()->right;
            st.pop();
        }
    }
    return st.top()->val;
}

// Time Complexity :- O(n) using inorder traversal with one stack;
