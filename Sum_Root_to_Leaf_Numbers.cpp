/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void helper(TreeNode* A, long long int &sum,long long int curr){

    if(A== NULL){
        return;
    }
    if(!A->left && !A->right){
        sum += (curr*10 + A->val)%1003;

        return;
    }
    helper(A->left,sum,((curr*10)%1003 + A->val)%1003);
    helper(A->right,sum,((curr*10)%1003 + A->val)%1003);
    return;
}
int Solution::sumNumbers(TreeNode* A) {
    string s;
    long long int sum = 0;
    helper(A,sum,0);
    return (sum)%1003;
}
