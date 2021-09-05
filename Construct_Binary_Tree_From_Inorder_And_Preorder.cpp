/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int i = 0;
TreeNode* helper(vector<int>&A,vector<int>&B,int s,int e){
    if(s > e){
        return NULL;
    }
    int idx = -1;
    for(int k = s; k <= e; k++){
        if(B[k] == A[i]){
            idx = k;
        }
    }
    if(idx != -1){
        TreeNode* n = new TreeNode(A[i]);
        i++;
        n->left = helper(A,B,s,idx-1);
        n->right = helper(A,B,idx+1,e);
        return n;
    }
    return NULL;
}
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
   i = 0;
   return helper(A,B,0,A.size()-1);
}
