/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode* fast = A;
    while(B > 0 && fast){
        fast = fast->next;
        B--;
    }
    if(B > 0){
        ListNode* temp = A->next;
        delete A;
        return temp;
    }
    ListNode* prev = NULL;
    ListNode* slow = A;
    while(fast){
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if(prev){
        prev->next = slow->next;
        delete slow;
        return A;
    }
    prev = A->next;
    delete A;
    return prev;
}
