int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int ans = 1;
    vector<int>dp(n,1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(A[j][1] < A[i][0]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}
