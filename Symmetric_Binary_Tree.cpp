/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool symmetry(TreeNode* A, TreeNode*B){
    if(!A && !B){
        return true;
    }
    if(!A || !B){
        return false;
    }
    if(A->val == B-> val && symmetry(A->left,B->right) && symmetry(A->right,B->left)){
        return true;
    }
    return false;
}
int Solution::isSymmetric(TreeNode* A) {
    return symmetry(A->left,A->right);
}
