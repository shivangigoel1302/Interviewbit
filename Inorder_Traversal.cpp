/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    stack<pair<TreeNode*,int>>s;
    s.push({A,1});
    vector<int>ans;
    while(!s.empty()){
        auto curr = s.top();
        s.pop();
        if(curr.first == NULL){
            continue;
        }
        if(curr.second == 1){
            s.push({curr.first->right,1});
            s.push({curr.first,2});
            s.push({curr.first->left,1});
        }
        else if(curr.second == 2){
            ans.push_back(curr.first->val);
        }
    }
    return ans;
}
