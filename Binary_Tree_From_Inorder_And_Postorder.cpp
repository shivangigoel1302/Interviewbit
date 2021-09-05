/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 int i;
TreeNode* helper(vector<int>&A,vector<int>&B,int s,int e){
    if(s > e){
        return NULL;
    }
    int idx = -1;
    for(int k = s; k <= e; k++){
        if(A[k] == B[i]){
            idx = k;
            break;
        }
    }
    if(idx != -1){
        TreeNode* n = new TreeNode(B[i]);
        i--;
        n->right =helper(A,B,idx+1,e);
        n->left = helper(A,B,s,idx-1);
        return n;
    }
    return NULL;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
     i = A.size()-1;
    return helper(A,B,0,A.size()-1);
}
