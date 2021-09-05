/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 void helper(TreeNode* &A){
     if(A == NULL){
         return;
     }
     if(A->left && !A->right){
         TreeNode* x = A->left;
         delete A;
         A = x;
     }
     if(A->right && !A->left){
         TreeNode* x = A->right;
         delete A;
         A = x;
     }
     helper(A->left);
     helper(A->right);
 }
TreeNode* Solution::solve(TreeNode* A) {
    helper(A);
    return A;
}
