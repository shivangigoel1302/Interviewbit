/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == NULL){
        return NULL;
    }
    if(!A->next){
        TreeNode* n = new TreeNode(A->val);
        return n;
    }
    ListNode* slow=A,*fast = A,*prev = NULL;
    while(fast && fast->next){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    TreeNode* n = new TreeNode(slow->val);
    ListNode* temp = slow->next;
    prev->next = NULL;
    n->left = sortedListToBST(A);
    n->right = sortedListToBST(temp);
    return n;
}
