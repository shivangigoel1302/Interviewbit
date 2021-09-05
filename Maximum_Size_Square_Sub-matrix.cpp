int Solution::solve(vector<vector<int> > &A) {
    int m = A.size(),n = A[0].size();
    int ans = 0;
    for(int i = 0; i < m; i++){
        if(A[i][0] == 1){
            ans = 1;
        }
    }
    for(int i = 0; i < n; i++){
        if(A[0][i] == 1){
            ans = 1;
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(A[i][j] == 1){
                A[i][j] += min(A[i-1][j],min(A[i][j-1],A[i-1][j-1]));
                ans = max(ans,A[i][j]);
            }
        }
    }
    return ans*ans;
}
