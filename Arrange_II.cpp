int helper(int st, int ed,int k,vector<vector<int>>&v,vector<vector<int>>&dp,string &A){
    if(st >= ed && k > 0 ){
        return INT_MAX/2;
    }
    if(dp[st][k] != -1){
        return dp[st][k];
    }
    if(k == 1){
        int w = v[ed-1][1] - (st > 0? v[st-1][1] : 0);
        int b = v[ed-1][0] - (st > 0 ? v[st-1][0] : 0);
        return (w*b);
    }

    int ans = INT_MAX/2;
    int w =0,b=0;
    for(int i = st; i < ed; i++){
        if(A[i] == 'W'){
            w++;
        }
        else{
            b++;
        }
        ans = min(ans, w*b + helper(i+1,ed,k-1,v,dp,A));
    }
    dp[st][k] = ans;
    return ans;
}
int Solution::arrange(string A, int B) {
    if(B > A.size()){
        return -1;
    }
    // sort(A.begin(),A.end());
    int n = A.size();
    vector<vector<int>>dp(n+1,vector<int>(B+1,-1));
    vector<vector<int>>v(A.size(),vector<int>(2,0));
    for(int i = 0; i < A.size(); i++){
        if(A[i] == 'B'){
            v[i][0] = 1;
        }
        else{
            v[i][1] = 1;
        }
        if(i > 0){
            v[i][0] += v[i-1][0];
        v[i][1] += v[i-1][1];

        }

    }
    return helper(0,A.size(),B,v,dp,A);
}
