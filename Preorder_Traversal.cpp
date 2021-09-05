/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*>s;
    s.push(A);
    vector<int>ans;
    while(!s.empty()){
        TreeNode* curr = s.top();
        s.pop();
        if(curr == NULL){
            continue;
        }
        ans.push_back(curr->val);
        s.push(curr->right);
        s.push(curr->left);
    }
    return ans;
}
