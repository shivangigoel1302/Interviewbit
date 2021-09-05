/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void reverse(ListNode* &head){
    ListNode* curr = head,*prev = NULL;
    while(curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) {
    int m = B;
    ListNode* prev = NULL;
    ListNode* start = A;
    while(m > 1){
        prev = start;
        start = start->next;
        m--;
    }
    int n = C-B;
    ListNode* end = start;

    while(n--){
        end = end->next;
    }

    ListNode* node = end->next;
    end->next = NULL;
    reverse(start);
    if(prev){
        prev->next = start;
    }
    else{
        A = start;
    }
    while(start->next){
        start = start->next;
    }
    start->next = node;
    return A;
}
