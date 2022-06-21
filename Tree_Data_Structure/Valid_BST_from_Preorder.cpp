// You are given a preorder traversal A, of a Binary Search Tree.

// Find if it is a valid preorder traversal of a BST.

// Note: Binary Search Tree by definition has distinct keys and duplicates in binary search tree are not allowed.

// Return an integer:

// 0 : Impossible preorder traversal of a BST
// 1 : Possible preorder traversal of a BST

int Solution::solve(vector<int> &preOrder) {
	stack<int> st;
	int root = INT_MIN;
	for(int i = 0; i < preOrder.size(); i++){
		while(!st.empty() && st.top() < preOrder[i]){
			root = st.top();
			st.pop();
		}
		if((!st.empty() &&st.top() == preOrder[i]) || preOrder[i] < root){
			return 0;
		}
		st.push(preOrder[i]);
	}
	return 1;
}

// Time complexity :- O(n) : single interation
// Space complexity :- O(n): to store each node
