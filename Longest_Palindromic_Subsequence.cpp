int Solution::solve(string A) {
    int n = A.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i = 0; i < A.size(); i++){
        dp[i][i]=1;
    }
    for(int k = 2; k <= n; k++){
        for(int i = 0; i < n-k+1; i++){
            int j = i + k -1;
            if(A[i] == A[j] && k == 2){
                dp[i][j] = 2;
            }
            else if(A[i] == A[j]){
                dp[i][j] = 2 + dp[i+1][j-1];
            }
            else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][n-1];
}
