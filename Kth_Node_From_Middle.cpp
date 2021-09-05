/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::solve(ListNode* A, int B) {
    ListNode*slow = A,*fast = A;
    while(fast && fast->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(B == 0){
        return slow->val;
    }
    fast = A;
    ListNode* temp = A;
    while(B-- && fast != slow->next){
        fast = fast->next;
    }
    if(fast == slow->next){
        return -1;
    }
    while(fast != slow ){
        temp = temp->next;
        fast = fast->next;
    }
    return temp->val;
}
