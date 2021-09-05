/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    stack<TreeNode*>s1;
    stack<TreeNode*>s2;
    s1.push(A);
    vector<vector<int>>ans;
    while(!s1.empty() || !s2.empty()){
        int sz;
        vector<int>temp;
        if(s1.empty()){
            sz = s2.size();
            while(sz--){
                TreeNode* curr = s2.top();
                s2.pop();
                temp.push_back(curr->val);
                if(curr->right){
                    s1.push(curr->right);
                }
                if(curr->left){
                    s1.push(curr->left);
                }
            }
        }
        else{
            sz = s1.size();
            while(sz--){
                TreeNode* curr = s1.top();
                s1.pop();
                temp.push_back(curr->val);
                if(curr->left){
                    s2.push(curr->left);
                }
                if(curr->right){
                    s2.push(curr->right);
                }
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
