// Two elements of a binary search tree (BST) are swapped by mistake.

// Tell us the 2 values swapping which the tree will be restored.

// Note:

// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

// Example :


// Input : 
//          1
//         / \
//        2   3

// Output : 
//        [1, 2]

// Explanation : Swapping 1 and 2 will change the BST to be 
//          2
//         / \
//        1   3
// which is a valid BST 

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
TreeNode *previous = NULL;
TreeNode *first = NULL;
TreeNode *middle = NULL;
TreeNode *last = NULL;
    
void inorder_traversal(TreeNode *root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    if(previous != NULL && (previous->val > root->val)){
        if(first == NULL){
            first = previous;
            middle = root;
        }else{
            last = root;
        }
    }
    previous = root;
    inorder_traversal(root->right);
}
    
vector<int> Solution::recoverTree(TreeNode* root) {
    first = last = middle = NULL;
    previous = new TreeNode(INT_MIN);
    inorder_traversal(root);
    if(first && last){
        vector<int> v{first->val, last->val};
        sort(v.begin(),v.end());
        return v;
    }else if(first && middle){
        vector<int> v{first->val, middle->val};
        sort(v.begin(),v.end());
        return v;
    }
}
