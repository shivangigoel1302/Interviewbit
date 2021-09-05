/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


ListNode* Solution::solve(ListNode* A, int B) {
    if(A == NULL){
        return NULL;
    }
    ListNode* curr = A;
    ListNode* prev = NULL;
    int cnt = 0;
    while(cnt < B && curr){
        ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
        cnt++;
    }
    if(curr){
        A->next = curr;
        cnt = 0;
        while(curr && cnt < B-1){
            curr = curr->next;
            cnt++;
        }
        curr->next = solve(curr->next,B);
    }
    return prev;
}
