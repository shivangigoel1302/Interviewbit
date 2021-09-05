/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::rotateRight(ListNode* A, int B) {
      int len = 0; // Find length first
    ListNode* ptr = A;
    while(ptr){
        len++;
        ptr = ptr->next;
    }
    B = B%len;
    if(B == 0) return A;
    len -= B; // Find position of node that would become our new node
    ptr = A;
    while(len>1){
        ptr = ptr->next;
        len--;
    }

    ListNode* curr = ptr->next;
    ptr->next = NULL;
    ListNode* head = curr;
    //Go up to the last node
    while(curr->next){
        curr = curr->next;
    }
    curr->next = A; // and make its next as our original head
    return head;
}
