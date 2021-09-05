vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    vector<vector<int>>ans;
    queue<TreeNode*>q;
    q.push(A);
    while(!q.empty()){
        int sz = q.size();
        vector<int>temp;
        while(sz--){
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
