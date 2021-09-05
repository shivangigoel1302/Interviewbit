int Solution::solve(const vector<int> &A) {
    if(A.size() <= 1){
        return A.size();
    }
    vector<unordered_map<int,int>>dp(A.size());
    int ans = 2;
    for(int i = 1; i < A.size(); i++){
        for(int j = 0; j < i; j++){
            int diff = A[i]- A[j];
            if(dp[j].find(diff) != dp[j].end()){
                dp[i][diff] = dp[j][diff] + 1;
                ans = max(ans,dp[i][diff]);
            }
            else{
                dp[i][diff] = 2;
            }
        }
    }
    return ans;
}
