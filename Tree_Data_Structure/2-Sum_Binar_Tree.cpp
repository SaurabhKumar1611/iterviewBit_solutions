// Given a binary search tree A, where each node contains a positive integer, and an integer B, you have to find whether or not there exist two different nodes X and Y such that X.value + Y.value = B.

// Return 1 to denote that two such nodes exist. Return 0, otherwise.


// Solution approach :- Inorder traversal of BST gives sorted array. Then the question is simple 2 sum problem and can be solved by two pointers

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void inorder_traversal(TreeNode *root, vector<int> &inorder){
    if(root){
        inorder_traversal(root->left, inorder);
        inorder.push_back(root->val);
        inorder_traversal(root->right, inorder);
    }
}

int solve(vector<int> arr, int target){
    int i = 0, j = arr.size() - 1;
    while(i < j){
        int temp_sum = arr[i] + arr[j];
        if(temp_sum == target){
            return 1;
        }else if(temp_sum < target){
            i++;
        }else{
            j--;
        }
    }
    return 0;
}

int Solution::t2Sum(TreeNode* root, int target) {
    vector<int> inorder;
    inorder_traversal(root, inorder);
    return solve(inorder, target);
}
