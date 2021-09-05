int Solution::numTrees(int A) {
    vector<int>dp(A+1,0);
    if(A == 0){
        return 0;
    }
    if(A <= 2){
        return A;
    }
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < A+1; i++){
        for(int j = 1; j <= i; j++){
            dp[i] += (dp[j-1]* dp[i-j]);
        }
    }
    return dp[A];
}
