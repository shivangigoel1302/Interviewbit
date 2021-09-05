int Solution::lis(const vector<int> &A) {
    int len = 1;
    vector<int>dp(A.size(),1);
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            if(A[j] <A[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        len = max(len,dp[i]);
    }
    return len;
}
