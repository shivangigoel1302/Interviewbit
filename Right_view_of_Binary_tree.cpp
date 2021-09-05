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
    vector<int>ans;
    queue<TreeNode*>q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        while(sz){
            auto temp = q.front();
            if(sz == 1){
                ans.push_back(temp->val);
            }
            q.pop();
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
           sz--;
        }
    }
    return ans;
}
