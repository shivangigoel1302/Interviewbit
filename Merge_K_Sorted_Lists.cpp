/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void insert(ListNode*&head,ListNode* &tail,int val){
    if(head == NULL){
        ListNode* n = new ListNode(val);
        head = n;
        tail = n;
        return;
    }
    ListNode* n = new ListNode(val);
    tail->next = n;
    tail = n;
    return;
}
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
    for(int i = 0; i < A.size(); i++){
        pq.push({A[i]->val,A[i]});
    }
    ListNode* head = NULL,*tail = NULL;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        insert(head,tail,x.first);
        if(x.second->next){
            pq.push({x.second->next->val,x.second->next});
        }
    }
    return head;
}
