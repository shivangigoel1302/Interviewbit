/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 void reverse(ListNode* &head){
     ListNode* curr = head;
     ListNode* prev = NULL;
     while(curr){
         ListNode* temp = curr->next;
         curr->next = prev;
         prev = curr;
         curr = temp;
     }
     head = prev;
     return;
 }
ListNode* Solution::solve(ListNode* A) {
    if(!A || !A->next || !A->next->next){
        return A;
    }
    ListNode* odd = A;
    ListNode* even = A->next;
    ListNode* ohead = A,*ehead = A->next;
    while(odd && even){
        if(even){
            odd->next = even->next;
            odd = odd->next;
        }
        if(odd){
            even->next = odd->next;
            even = even->next;
        }
    }
    if(odd){
        odd->next= NULL;
    }
    if(even){
        even->next = NULL;
    }
    reverse(ehead);
    while(ehead && ohead){
        ListNode* temp = ohead->next;
        ohead->next = ehead;
        ohead = temp;
        temp = ehead->next;
        ehead->next = ohead;
        ehead = temp;
    }
    return A;
}
