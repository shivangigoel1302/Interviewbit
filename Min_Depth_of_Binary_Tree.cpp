/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
    if(!A){
        return 0;
    }
    if(!A->left && !A->right){
        return 1;
    }
    int l = INT_MAX,r=INT_MAX;
    if(A->left){
      l = minDepth(A->left);
    }
    if(A->right){
        r = minDepth(A->right);
    }
    return min(l,r)+1;
}
