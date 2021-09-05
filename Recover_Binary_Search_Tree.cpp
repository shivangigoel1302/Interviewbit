/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void helper(vector<pair<int,int>>&v,TreeNode* root,int& prev){
     if(root == NULL){
         return;
     }
     helper(v,root->left,prev);
     if(root->val < prev){
         v.push_back({prev,root->val});
     }
     prev = root->val;
     helper(v,root->right,prev);
 }
vector<int> Solution::recoverTree(TreeNode* A) {
    vector<pair<int,int>>v;
    int prev = INT_MIN;
    helper(v,A,prev);
    if(v.size() == 1){
        return {v[0].second,v[0].first};
    }
    else{
        return {v[1].second,v[0].first};
    }
}
