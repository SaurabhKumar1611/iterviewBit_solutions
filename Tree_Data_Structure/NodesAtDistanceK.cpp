// Given the root of a binary tree A, the value of a target node B, and an integer C, return an array of the values of all nodes that have a distance C from the target node.

// You can return the answer in any order.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool preorder(TreeNode *root, vector<TreeNode *> &path, vector<int> &direction, int target){
    if(root == NULL){
        return 0;
    }
    path.push_back(root);
    direction.push_back(0);
    if(root->val == target){
        return 1;
    }
    direction[direction.size() - 1] = 1;
    if(preorder(root->left, path, direction, target)){
        return 1;
    }
    direction[direction.size() - 1] = -1;
    if(preorder(root->right, path, direction, target)){
        return 1;
    }
    direction.pop_back();
    path.pop_back();
    return 0;
}

void findNodesAtk(TreeNode *root, vector<int> &nodes_at_k, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        nodes_at_k.push_back(root->val);
        return;
    }
    findNodesAtk(root->left, nodes_at_k, k - 1);
    findNodesAtk(root->right, nodes_at_k, k - 1);
} 

vector<int> Solution::distanceK(TreeNode* root, int target, int k) {
    vector<TreeNode *> path;
    vector<int> direction;
    preorder(root, path, direction, target);
    vector<int> nodes_at_k;
    int i = 1;
    while(i <= path.size()){
        int temp_distance = path.size() - i;
        if(temp_distance == k){
            nodes_at_k.push_back(path[i - 1]->val);
        }else if(temp_distance < k){
            if(direction[i - 1] == 1){
                findNodesAtk(path[i - 1]->right, nodes_at_k, k - temp_distance - 1);
            }else if(direction[i - 1] == -1){
                findNodesAtk(path[i - 1]->left, nodes_at_k, k - temp_distance - 1);
            }else{
                findNodesAtk(path[i - 1], nodes_at_k, k - temp_distance);
            }
        }
        i++;
    }
    return nodes_at_k;
}
