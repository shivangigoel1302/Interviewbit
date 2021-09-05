/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int search(vector<int>&ans,TreeNode* root,int b){
    if(root == NULL){
        return 0;
    }
    int l = search(ans,root->left,b);
    int r = search(ans,root->right,b);
    if(root->val == b){
        ans.push_back(b);
        return 1;
    }
    if(l || r){
        ans.push_back(root->val);
    }
    return l || r;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ans;
    search(ans,A,B);
    reverse(ans.begin(),ans.end());
    return ans;
}
