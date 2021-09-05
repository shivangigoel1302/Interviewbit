/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(!A && !B){
        return true;
    }
    if(!A || !B){
        return false;
    }
    if(A->val == B->val && isSameTree(A->right,B->right) && isSameTree(A->left,B->left)){
        return true;
    }
    return false;
}
