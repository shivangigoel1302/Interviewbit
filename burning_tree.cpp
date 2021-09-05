/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
map<TreeNode*,pair<int,int>> mp;
int ans;

int dfs(TreeNode* A){
    int lh=0,rh=0;

    if(A->left) lh = dfs(A->left);
    if(A->right) rh = dfs(A->right);

    mp[A] = {lh,rh};

    return max(lh,rh) + 1;
}

int calc(TreeNode* A, int B){
    int lh=0,rh=0;
    if(A->val==B){
        ans = max(ans,max(mp[A].first,mp[A].second));
        return 1;
    }

    if(A->left) lh = calc(A->left,B);
    if(A->right) rh = calc(A->right,B);

    if(lh>=1){
        ans = max(ans,mp[A].second + lh);
        return lh+1;
    }
    else if(rh>=1){
        ans = max(ans,mp[A].first + rh);
        return rh+1;
    }
    else return -1;
}

int Solution::solve(TreeNode* A, int B) {
    if(A==NULL || (A->left==NULL && A->right==NULL)) return 0;
    ans=0;
    dfs(A);
    calc(A,B);
    return ans;
}
