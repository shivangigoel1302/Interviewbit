int getmin(vector<int>adj[],int root,int &ans){
    int minimum = 0;
    int maximum = 0;
    for(auto nbr: adj[root]){
        int x = getmin(adj,nbr,ans);
        if(x > maximum){
            minimum = maximum;
            maximum = x;
        }
        else if(x > minimum){
            minimum = x;
        }
    }

    ans = max(ans,minimum+maximum);
    return maximum+1;
}
int Solution::solve(vector<int> &A) {
    int root;
    vector<int>adj[A.size()];
    for(int i = 0; i < A.size(); i++){
        if(A[i] == -1){
            root = i;
        }
        else{
         adj[A[i]].push_back(i);
        }
    }
    int ans=0;
    getmin(adj,root,ans);
    return ans;
}
