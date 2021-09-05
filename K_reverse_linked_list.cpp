/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseList(ListNode* A, int B) {
    if(A == NULL){
        return NULL;
    }

   ListNode* prev = NULL,*curr = A;
   int a = B;
   while(a--){
       ListNode* temp = curr->next;
       curr->next = prev;
       prev = curr;
       curr = temp;
   }
   A->next = reverseList(curr,B);
   return prev;
}
