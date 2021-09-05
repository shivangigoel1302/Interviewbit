/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 stack<TreeNode*>s;

BSTIterator::BSTIterator(TreeNode *root) {
    TreeNode* l = root;
    while(l){
        s.push(l);
        l = l->left;
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    if(s.empty()){
        return false;
    }
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode* top = s.top();
    int ans = top->val;
    s.pop();
        top = top->right;
    while(top){
        s.push(top);
        top = top->left;
    }
    return ans;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
