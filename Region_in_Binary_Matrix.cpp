int xdir[8] = {1,1,0,-1,-1,-1,0,1};
int ydir[8] = {0,1,1,1,0,-1,-1,-1};
int removearea(vector<vector<int>>&A,int i,int j){
    if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size() || A[i][j] == 0){
        return 0;
    }
    int curr = 0;
    A[i][j] = 0;
    for(int k = 0; k < 8; k++){
        curr += removearea(A,i+xdir[k],j+ydir[k]);
    }
    return curr +1;
}
int Solution::solve(vector<vector<int> > &A) {
    int ans = INT_MIN;
    int m = A.size();
    int n = A[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 1){
                ans = max(ans,removearea(A,i,j));
            }
        }
    }
    return ans;
}
