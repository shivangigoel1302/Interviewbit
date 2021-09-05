/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 */
bool helper(unordered_map<int,bool>&m,TreeNode* root,int b){
    if(root == NULL){
        return false;
    }
    if(root->val < b){
        if(m.find(b-root->val) != m.end()){
            return true;
        }
        m[root->val] = 1;
    }
    return (helper(m,root->left,b) || helper(m,root->right,b));
}
int Solution::t2Sum(TreeNode* A, int B) {
    unordered_map<int,bool>m;
    return helper(m,A,B);

}
