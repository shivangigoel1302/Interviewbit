/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::swapPairs(ListNode* A) {
    if(A == NULL){
        return NULL;
    }
    if(!A->next){
        return A;
    }
    ListNode* prev = NULL,*curr = A;
    int a = 2;
    while(a--){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    A->next = swapPairs(curr);
    return prev;
}
