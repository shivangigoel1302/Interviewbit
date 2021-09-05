/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::solve(ListNode* A) {
    if(!A){
        return NULL;
    }
    ListNode*head = A,*prev = A,*temp = A->next;
    while(temp){
        if(temp->val == 1){
            prev = prev->next;
            temp = temp->next;
        }
        else{
            prev->next = temp->next;
            temp->next = head;
            head = temp;
            temp = prev->next;
        }
    }
    return head;
}
