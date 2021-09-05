/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode* Solution::reorderList(ListNode* A) {
     ListNode *slow = A;
    ListNode *temp2 = A;
    ListNode *fast = A->next;
    if(fast==NULL) return A;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *A1=slow->next;
    slow->next=NULL;
    ListNode *curr = A1;
    ListNode *prev = A1;
    while(curr->next!=NULL){
        ListNode *temp = curr->next;
        curr->next = temp->next;
        temp->next = prev;
        prev = temp;
    }
    A1 = prev;
    while(A1!=NULL){
        ListNode *temp = A->next;
        ListNode *temp1 = A1->next;
        A->next = A1;
        A1->next = temp;
        A= temp;
        A1=temp1;
    }
    return temp2;
}

