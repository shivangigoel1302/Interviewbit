int Solution::climbStairs(int A) {
    vector<int>dp(A+1);
    dp[0] = 1;
    for(int i = 1; i <= A; i++){
        if(i >= 2){
            dp[i] += dp[i-2];
        }
        dp[i] += dp[i-1];
    }
    return dp[A];
}
