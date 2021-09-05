void dfs(vector<string>&A,vector<vector<int>>&ans,int i,int j,int x,int y){
    if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size()){
        return;
    }
    ans[i][j]++;
    if(A[i][j] == '0'){
        dfs(A,ans,i+x,j+y,x,y);
    }
    return;
}
vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int>>ans(m,vector<int>(n,0));
    int xdir[8] = {1,1,0,-1,-1,-1,0,1};
    int ydir[8] = {0,1,1,1,0,-1,-1,-1};
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == '1'){
                for(int k = 0; k < 8; k++){
                    dfs(A,ans,i+xdir[k],j+ydir[k],xdir[k],ydir[k]);
                }
            }
        }
    }
    return ans;
}
