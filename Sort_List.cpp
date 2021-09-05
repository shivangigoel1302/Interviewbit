/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* middle(ListNode* head){
    if(head == NULL){
        return NULL;
    }
    ListNode* slow = head, *fast = head->next;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
ListNode* mergesort(ListNode* a, ListNode* b){
    if(!a && !b){
        return NULL;
    }
    if(!a){
        return b;
    }
    if(!b){
        return a;
    }
    if(a->val < b->val){
        a->next = mergesort(a->next,b);
        return a;
    }
    else{
        b->next = mergesort(a,b->next);
        return b;
    }
    return NULL;
}
ListNode* merge(ListNode*head){

    if(!head){
        return NULL;
    }
    if(!head->next){
        return head;
    }
    ListNode* mid = middle(head);
    ListNode* nhead = mid->next;
    mid->next = NULL;
    ListNode* l = merge(head);
    ListNode* r = merge(nhead);
    return mergesort(l,r);
}
ListNode* Solution::sortList(ListNode* A) {

    return merge(A);
}
