int Solution::solve(vector<int> &A) {
    int sum = 0;
    int n  = A.size();
    for(int i = 0; i < n; i++){
        sum += A[i];
    }
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,false));
    for(int i = 0; i < n+1; i++){
        dp[i][0] = true;
    }
    for(int i = 1; i < sum+1; i++){
        dp[0][i] = false;
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j <= sum; j++){
            if(A[i-1] <= j){
                dp[i][j] = (dp[i-1][j] || dp[i-1][j-A[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int mn = INT_MAX;
    for(int i =0; i < sum+1; i++){
        if(dp[n][i]){
            mn = min(mn,abs(sum-2*i));
        }
    }
    return mn;
}
