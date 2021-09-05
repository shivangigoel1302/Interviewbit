int Solution::numDistinct(string A, string B) {
    int n = A.size();
    int m = B.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i = 0; i < n+1; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}
