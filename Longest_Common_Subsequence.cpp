int Solution::solve(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
