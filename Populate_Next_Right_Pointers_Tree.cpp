/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    queue<TreeLinkNode*>q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        while(sz > 0){
            TreeLinkNode* curr = q.front();
            q.pop();
            if(sz != 1){
                curr->next = q.front();
            }
            else{
                curr->next = NULL;
            }
            if(curr->left){
                q.push(curr->left);
            }
            if(curr->right){
                q.push(curr->right);
            }
            sz--;
        }
    }
    return;
}
