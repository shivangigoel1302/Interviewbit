/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    queue<TreeNode*>q;
    q.push(A);
    bool found = false;
    vector<int>ans;
    if(A->val == B){
        return {};
    }
    while(!q.empty() && !found){
        int sz = q.size();
        while(sz--){
            auto temp = q.front();
            q.pop();
            if( (temp->left && temp->left->val == B) ||(temp->right && temp->right->val == B)){
                found = true;
                continue;
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(found){
            while(!q.empty()){
                ans.push_back(q.front()->val);
                q.pop();
            }
        }
    }
    return ans;
}
