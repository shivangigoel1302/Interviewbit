bool ispalindrome(string s){
    int st = 0;
    int ed = s.size()-1;
    while(st <= ed){
        if(s[st] != s[ed]){
            return false;
        }
        st++;
        ed--;
    }
    return true;
}
int helper(string A,int i,int n,vector<int>&dp){
    if(dp[i] != -1){
        return dp[i];
    }
    if(i >= n){
        return 0;
    }
    if(ispalindrome(A.substr(i))){
        return dp[i] = 0;
    }
    int cuts = INT_MAX;
    for(int s = 1; s <= n-i; s++){
        if(ispalindrome(A.substr(i,s))){
            cuts = min(helper(A,i+s,n,dp),cuts);
        }
    }
    return dp[i] = cuts + 1;
}
int Solution::minCut(string A) {
    vector<int>dp(A.size(),-1);
    return helper(A,0,A.size(),dp);
}
