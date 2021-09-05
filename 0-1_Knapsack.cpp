int Solution::solve(vector<int> &a, vector<int> &b, int c) {
    vector<vector<int>> dp(a.size()+1,vector<int>(c+1, 0));
    for(int i=1; i<=a.size(); i++)
    {
        for(int j=1; j<=c; j++)
        {
            int x = 0;
            if(b[i-1] <= j) x = dp[i-1][j-b[i-1]]+a[i-1];
            dp[i][j] = max(x,dp[i-1][j]);
        }
    }
    return dp[a.size()][c];
}
