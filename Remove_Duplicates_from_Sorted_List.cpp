/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curr = A;
    while(curr){
        int val = curr->val;
        while(curr->next && curr->next->val == val){
            ListNode* node = curr->next;
            curr->next = node->next;
            delete node;
        }
        curr = curr->next;
    }
    return A;
}
