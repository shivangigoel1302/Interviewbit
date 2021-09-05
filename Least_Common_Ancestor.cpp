/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findlca(TreeNode* A, int B,int C, TreeNode* &ans){
    if(A == NULL){
        return 0;
    }
    int l = findlca(A->left,B,C,ans);
    int r = findlca(A->right,B,C,ans);
    int m = 0;
    if(A->val == B ){
        m = 1;
    }
    if(A->val == C){
        m++;
    }
    if(l +r + m >= 2){
        ans = A;
    }
    return (l+r+m >=1);
}
int Solution::lca(TreeNode* A, int B, int C) {
    TreeNode* ans=NULL;
    findlca(A,B,C,ans);
    if(!ans){
        return -1;
    }
    return ans->val;
}
