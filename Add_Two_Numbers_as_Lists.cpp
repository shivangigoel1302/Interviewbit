/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode*head = new ListNode(0);
    ListNode* temp = head;
    ListNode* ptr1 = A,*ptr2 = B;
    int carry = 0;
    while(ptr1 || ptr2){
        int a = ptr1? ptr1->val : 0;
        int b = ptr2? ptr2->val : 0;
        if(ptr1){
            ptr1=ptr1->next;
        }
        if(ptr2){
            ptr2=ptr2->next;
        }
        ListNode* n = new ListNode((a+b+carry)%10);
        temp->next = n;
        temp = n;
        carry = (a+b+carry)/10;
    }
    if(carry){
        ListNode* n = new ListNode(carry);
        temp->next = n;
    }
    return head->next;
}
