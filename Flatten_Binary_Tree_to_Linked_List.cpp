/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* &A){
    if(!A){
        return;
    }
    TreeNode* curr = A;
    if(curr->left){
        // right most of left
        TreeNode* m = curr->left;
        while(m->right){
            m = m->right;
        }
        TreeNode* r = curr->right;
        curr->right = curr->left;
        curr->left = NULL;
        m->right = r;
    }
    helper(A->right);
}
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    helper(A);
    return A;

}
