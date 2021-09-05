/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*>q;
    q.push(A);
    vector<int>ans;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            TreeNode* curr = q.front();
            q.pop();
            while(curr){
                ans.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                curr = curr->right;
            }
        }
    }
    return ans;
}
