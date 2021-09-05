/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* A,int b,bool &found ,int sum){
    if(!A){
        return;
    }
    if(!A->left && !A->right){

        if(sum+A->val == b){
            found = true;
        }
        return;
    }
    if(found){
        return;
    }
    helper(A->left,b,found,sum+A->val);
    helper(A->right,b,found,sum+A->val);
    return;
}
int Solution::hasPathSum(TreeNode* A, int B) {
    bool found = false;
    helper(A,B,found,0);
    return found;
}
