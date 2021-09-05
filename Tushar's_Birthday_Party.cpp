void findcost(int target,const vector<int> &b,const vector<int> &c,vector<vector<int>>&dp){
    int m = b.size();
    vector<pair<int,int>>v;
    for(int i = 0; i < m; i++){
        v.push_back({b[i],c[i]});
    }
    sort(v.begin(),v.end());

    for(int i  = 0; i < dp.size(); i++){
        dp[i][0] = 0;
    }

    for(int i = 1; i < m+1; i++){
        for(int j = 1; j <= target; j++){
            if(j >= v[i-1].first){
                dp[i][j] = min(dp[i-1][j],dp[i][j-v[i-1].first]+v[i-1].second);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return;
}

int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    int cost = 0;
    int m = B.size();
    vector<vector<int>>dp(m+1,vector<int>(1001,INT_MAX));
    findcost(1001,B,C,dp);
    for(int i = 0; i < A.size(); i++){
        cost += dp[m][A[i]];
    }
    return cost;
}
