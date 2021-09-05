int Solution::solve(int A, int B) {
    vector<vector<int>>dp(A+1,vector<int>(B+1,0));
    int mod = 1e9+7;
    for(int i = 1; i <= B; i++){
        dp[1][i] = (i <= 9);
    }
    for(int i = 2; i <= A; i++){
        for(int j = 1; j <= B; j++){
            for(int k = 0; k <= 9 && j-k >= 0 ; k++){
                dp[i][j] += dp[i-1][j-k];
                dp[i][j] %= mod;
            }
        }
    }
    return dp[A][B];
}
