int helper(vector<int>&A,vector<vector<int>>&dp,int i, int j){
    if(i == j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans = INT_MAX;
    int sum = 0;
    for(int k = i; k <= j; k++){
        sum += A[k];
    }
    for(int k = i; k< j; k++){
        ans = min(ans,sum + helper(A,dp,i,k) + helper(A,dp,k+1,j));
    }
    dp[i][j] = ans;
    return ans;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return helper(A,dp,0,n-1);
}
