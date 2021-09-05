/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* &ans, TreeNode*& root, int& k){
     if(root == NULL){
         return;
     }
     if(ans != NULL){
         return;
     }
     helper(ans,root->left,k);
     k--;
     if(k == 0){
         ans = root;
     }
     helper(ans,root->right,k);
     return;
 }
int Solution::kthsmallest(TreeNode* A, int B) {
    TreeNode* ans = NULL;
    helper(ans,A,B);
    return ans->val;
}
