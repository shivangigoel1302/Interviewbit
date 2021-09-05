/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(vector<int>&A,int i,int j){
    if(i > j){
        return NULL;
    }
    int maximum = INT_MIN,idx=-1;
    for(int k = i; k <= j; k++){
        if(A[k] > maximum){
            idx = k;
            maximum = A[k];
        }
    }
    TreeNode* n = new TreeNode(maximum);
    n->left = helper(A,i,idx-1);
    n->right = helper(A,idx+1,j);
    return n;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    return helper(A,0,A.size()-1);
}
