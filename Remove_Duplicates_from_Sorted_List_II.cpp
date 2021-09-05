/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* curr = A;
    ListNode* prev = NULL;
    while(curr){
        if(curr->next && curr->val == curr->next->val){
            int val = curr->val;
            while(curr && curr->val == val){
                if(prev){
                    prev->next = curr->next;
                    delete curr;
                    curr = prev->next;
                }
                else{
                    //cout<<curr->val<<" ";
                    ListNode* temp = curr->next;
                    delete curr;
                    curr = temp;
                }
            }
        }
        else{
            if(!prev){
                A = curr;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    if(!prev){
        return NULL;
    }
    return A;
}
