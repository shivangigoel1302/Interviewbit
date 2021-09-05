/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::insertionSortList(ListNode* A) {
    if(!A){
        return A;
    }
    ListNode* curr = A;
    while(curr->next){
        if(curr->next->val < curr->val){
            int x = curr->next->val;
            ListNode* node = curr->next->next;
            ListNode* prev = NULL;
            ListNode* temp = A;
            while(temp->val < x){
                prev = temp;
                temp = temp->next;
            }
            if(prev){
                prev->next = curr->next;
                curr->next->next = temp;
            }
            else{
                A = curr->next;
                curr->next->next = temp;
            }
            curr->next = node;
        }
        else{
            curr = curr->next;
        }
    }
    return A;
}
