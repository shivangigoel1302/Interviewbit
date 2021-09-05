/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(vector<int>temp,vector<vector<int>>&ans,TreeNode* A,int b,int curr){
    if(!A){
        return;
    }
    if(!A->right && !A->left){
        if(curr + A->val == b){
            temp.push_back(A->val);
            ans.push_back(temp);
            temp.pop_back();
        }
        return;
    }
    temp.push_back(A->val);
    helper(temp,ans,A->left,b,curr+A->val);
    helper(temp,ans,A->right,b,curr+A->val);
    temp.pop_back();
    return;
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int>>ans;
    vector<int>temp;
    helper(temp,ans,A,B,0);
    return ans;
}
