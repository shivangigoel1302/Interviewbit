/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* helper(const vector<int>&A,int i,int j){
    if(i > j){
        return NULL;
    }
    int mid = (i+j)/2;
    TreeNode* n = new TreeNode(A[mid]);
    n->left = helper(A,i,mid-1);
    n->right = helper(A,mid+1,j);
    return n;
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return helper(A,0,A.size()-1);
}
