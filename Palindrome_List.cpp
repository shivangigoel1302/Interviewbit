/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

 */
 bool reached = false;
 bool helper(ListNode* tail,ListNode* &head){
     if(tail == NULL){
         return true;
     }
     if(!helper(tail->next,head)){
         return false;
     }
     if(reached){
         return true;
     }
     if(tail->val == head->val){
         head = head->next;
         return true;
     }
     else if(tail->val != head->val){
         return false;
     }
     if(head == tail){
         reached = true;
         return true;
     }
 }
int Solution::lPalin(ListNode* A) {
    ListNode* tail = A;
    ListNode* head = A;
    return helper(tail,head);
}
