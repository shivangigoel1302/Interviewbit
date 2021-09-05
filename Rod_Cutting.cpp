long long helper(int st,int ed, vector<int>&B,vector<vector<long long>>&dp,vector<vector<int>>&cuts){
    if(abs(ed-st) <=1){
        return 0;
    }
    if(dp[st][ed] != -1){
        return dp[st][ed];
    }
    long long ans = INT_MAX;
    int idx = -1;
    for(int i = st+1; i < ed; i++){
        long long temp =B[ed]-B[st] + helper(st,i,B,dp,cuts) + helper(i,ed,B,dp,cuts);
        if(ans == INT_MAX || temp < ans){
            ans = temp;
            idx = i;
        }
    }
    dp[st][ed] = ans;
    cuts[st][ed] = idx;
    return ans;
}
void fill(vector<int>&ans,vector<int>B,vector<vector<int>>cuts,int st,int ed){
    if(abs(ed-st) <= 1){
        return;
    }
    ans.push_back(B[cuts[st][ed]]);
    fill(ans,B,cuts,st,cuts[st][ed]);
    fill(ans,B,cuts,cuts[st][ed],ed);
}
vector<int> Solution::rodCut(int A, vector<int> &B) {
    B.push_back(0);
    B.push_back(A);
    sort(B.begin(), B.end());
    int m = B.size();
    vector<vector<long long>>dp(m,vector<long long>(m,-1));
    vector<vector<int>>cuts(m,vector<int>(m));
    helper(0,m-1,B,dp,cuts);
    vector<int>ans;
    fill(ans,B,cuts,0,m-1);
    return ans;
}
