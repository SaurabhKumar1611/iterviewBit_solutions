// Given inorder and postorder traversal of a tree, construct the binary tree.

// Note: You may assume that duplicates do not exist in the tree.

// Example :

// Input : 
//         Inorder : [2, 1, 3]
//         Postorder : [2, 3, 1]

// Return : 
//             1
//            / \
//           2   3

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int i;

TreeNode *build(const vector<int> &inorder, const vector<int> &postorder, int start, int end){
    if(start > end){
        return NULL;
    }
    TreeNode *root = new TreeNode(postorder[i]);
    int pivot = start;
    while(pivot <= end && postorder[i] != inorder[pivot]){
        pivot ++;
    }
    i --;
    root->right = build(inorder, postorder, pivot + 1, end);
    root->left = build(inorder, postorder, start, pivot - 1);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    if(inorder.size() == NULL){
        return NULL;
    }
    i = postorder.size() - 1;
    TreeNode *root = build(inorder, postorder, 0, postorder.size() - 1);
    return root;
}
