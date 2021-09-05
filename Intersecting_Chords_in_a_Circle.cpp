int mod = 1e9+7;
int helper(int A,vector<int>&dp){
    if(A == 0 || A == 2){
        return 1;
    }
    if(dp[A] != -1){
        return dp[A];
    }
    long long ans = 0;
    for(int i = 0; i < A; i+=2){
        long long left = helper(i,dp);
        long long right = helper(A-i-2,dp);
        ans = (ans%mod + (left*right)%mod)%mod;
    }
    dp[A] = ans%mod;
    return ans%mod;
}
int Solution::chordCnt(int A) {
    vector<int>dp(2*A+1,-1);
    return helper(2*A,dp);
}
