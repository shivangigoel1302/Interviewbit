/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int helper(TreeNode* root,int &ans){
    if(!root)
    {
        return 0;
    }
    int l=helper(root->left,ans);
    int r=helper(root->right,ans);
    int val=root->val+max(l,r);
    ans=max(ans,max(val,max(root->val,l+root->val+r)));
    return max(val,root->val);
}
int Solution::maxPathSum(TreeNode* A) {
    int ans = INT_MIN;
    helper(A,ans);
    return ans;
}
