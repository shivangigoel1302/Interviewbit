/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
   ListNode* great = A;
   ListNode* less = NULL;
   while(great && great->val < B){
       less = great;
       great = great->next;
   }
   ListNode* gtail = great;
   ListNode* curr = great->next;
   while(curr){
       if(curr->val < B){
           ListNode* temp = curr->next;
           curr->next = great;
           if(less){
               less->next = curr;
               less = less->next;
           }
           else{
               A = curr;
               less = A;
           }
           gtail->next = temp;
           curr = temp;
       }
       else{
           gtail = curr;
           curr = curr->next;
       }
   }
   return A;
}
